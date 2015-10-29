# Ride.Kit

Ride.Kit provides application developers with the opportunity to interoperate with 3rd party transportation and travel applications through deep cross-app linking. The designer and developer of transportation, navigation, and travel apps can now integrate third party services for carshare, mobile ticketing, hotel booking, bikeshare, rideshare, and taxi services in minutes with a few lines of code. The sdk facilitates the exchange of application functionality to the Connect Network.

- For the complete integration guide with images and Swift examples go to http://sdk.ridescout.com/content/iOS
- For the complete documentation go to http://documentation.ridescout.com/ios/

#Step 1: Installation

```ruby
platform :ios, '7.0'
pod "RideKitFramework", "~> 1.0.0"
```

#Step 2: Create an iOS App for Ride.Kit

Go to http://sdk.ridescout.com/register and register for an account. Then go to http://sdk.ridescout.com/addapp/ to add your app to receive your API key.

#Step 3: Setup a URL Scheme

In your AppDelegate add the following code:
```objective-c
// Objective-C
-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    if ([[RKManager sharedService] handleOpenURL:url]) {
        return YES;
    }
    return NO;
}
```
```swift
// Swift
func application(application: UIApplication, handleOpenURL url: NSURL) -> Bool {
    if (RKManager.sharedService().handleOpenURL(url)) {
        return true
    }
    return true
}
```
Then go to Build Phases in the project editor and click on the Info tab. Click the plus icon in the URL Types to create a custom URL Scheme for your app. Hint: This must be unique in order for this to work so create a custom url scheme unique to your app.

#Step 4: Starting Ride.Kit

The following steps should be done in your application:didFinishLaunchingWithOptions in your AppDelegate or a view controller that is loaded upon app launch.

Import the framework header.
```objective-c
// Objective-C
#import <RideKit/RideKit.h>
```

To create your own features for other apps in the Ride.Kit Network to use add the following line of code per feature

```objective-c
// Objective-C
RKFeature *feature = [[RKFeature alloc] initWithName:@”Feature name” type:RKFeatureType<Pick a type> andRequestHandler:^(NSDictionary *parameters) {
    // Code to implement the feature.
    
    // This line of code is optional if you want to return the results to the calling app
    [[RKManager sharedService] returnResults:@{@"json":@"object"}];
}];
```
```swift
// Swift
let feature: RKFeature = RKFeature(name: "Feature name", type:RKFeatureType.<Pick a type>, andRequestHandler: {(params: [NSObject: AnyObject]?) -> Void in
    // Code to implement feature

    // This line of code is optional if you want to return the results to the calling app
    RKManager.sharedService().returnResults(["success":true])
})
```

Then create the configuration with your API Key from step 2 and custom URL Scheme from step 3

```objective-c
// Objective-C
RKConfiguration *config = [[RKConfiguration alloc] initWithApiKey:@"<API Key>" callbackUrlScheme:@"<URL Scheme from step 3>" andFeatures:@[feature1, feature2, ...]];
```
```swift
// Swift
let config: RKConfiguration = RKConfiguration(apiKey: "<API key>", callbackUrlScheme:"<URL Scheme from step 3>", andFeatures: [feature1, feature2, ...])
```

You can now start the Ride.Kit with the following line of code

```objective-c
// Objective-C
[[RKManager sharedService] startRideKitWithConfiguration:config completion:^(NSArray *providers) { 
    // Code to use the other (not your app) providers from the Ride.Kit Network which contain their features. 

}];
```
```swift
// Swift
RKManager.sharedService().startRideKitWithConfiguration(config, completion: { (providers: [AnyObject]!) -> Void in
     // Code to use the other (not your app) providers from the Ride.Kit Network which contain their features. 

})
```

#Step 5: Execute features from the Ride.Kit Network

In step 4 starting the Ride.Kit will return an array of RKProvider objects which contains an array of RKFeature objects. These are the features that are available in the Ride.Kit Network and can be utilized with the following line of code

```objective-c
// Objective-C
[feature setParameters:@{@"json":@"object"}]; // If the feature requires parameters
[[RKManager sharedService] executeFeature:feature withResultsHandler:^(NSDictionary *results) {
    // Code to implement results if the feature returns results

}];
```
```swift
// Swift
feature.parameters = ["json":"object"]
RKManager.sharedService().executeFeature(feature, withResultsHandler: { (results: [NSObject: AnyObject]?) -> Void in
    // Code to implement results

})
```

To see a list of all of the features in the Ride.Kit Network along with their parameters and return results go to http://sdk.ridescout.com/ecosystem

#Step 6: Logging in with Ride.Kit

Option 1: Use the RKLoginButtonDark or RKLoginButtonLight with interface builder or code.
Option 2: Create your own custom login button and in your IBAction add the following line of code

```objective-c
// Objective-C
[RKLoginManaget getRideScoutAccessTokenAndLogin];
```
```swift
// Swift
RKLoginManager.getRideScoutAccessTokenAndLogin()
```

Add the RideKitDelegate protocol and implement the delegate method

```objective-c
// Objective-C
- (void)loggedInWithProfile:(RKProfile *)profile {

}
```
```swift
// Swift
func loggedInWithProfile(profile: RKProfile!) {

}
```

#License
 
RIDESCOUT, LLC

SDK LICENSE AGREEMENT
This SDK License Agreement (the “Agreement”) is for the RideScout, LLC (“Company”) software development kit and any associated tools and documentation made available by Company (the “SDK” or “Ride.Kit”) to enable users to integrate their mobile applications with Company’s proprietary SDK functionality. By downloading, accessing, using, copying, or distributing the SDK, you and any company, entity, or organization on behalf of which you are accepting this Agreement hereby agree to be bound by this Agreement. If you do not agree to this Agreement, do not download, access, or use the SDK. This Agreement is effective as of the date of first download, access, or use of the SDK (“Effective Date”). 

Definitions. In addition to those terms defined in the body of the Agreement, the following capitalized terms have the meanings set forth below:
“Aggregate Usage Data” means information and data that a party develops or produces using the Customer Data that in each case is aggregated or for which commercially reasonable steps have been taken to ensure that such data and information does not personally identify any individual.
“API” means application programming interface.
 “Confidential Information” means any non-public information provided by one party to the other which is identified as confidential or should reasonably be considered confidential given the nature of the information and the circumstances of disclosure, including, without limitation, technical data, product plans, and financial information. 
 “Customer” means any customer to whom you provide access to Your Platform. 
“Customer Data” means any data or information that (i) a Customer submits or provides to you through Your Platform or (ii) a Customer submits or provides in connection with the Company Platform where such data or information is collected on your behalf or is transferred to or otherwise accessible by you. 
“Company Marks” means Company’s trademarks, trade names, service marks, and logos.
“Company Platform” means Company’s proprietary software platform. 
“SDK” means the software development kit and any associated APIs, tools and documentation that Company makes available to enable you to perform deep linking integration among mobility software applications.
 “SDK Modifications” means any modifications you make to sample code included in the SDK. 
“Your Platform” means your mobile software applications.
The SDK. 
License to You. Subject to your compliance with the terms and conditions of the Agreement, Company grants you a non-exclusive, non-transferable, and worldwide license to (a) use the object code libraries, APIs and documentation specified in the SDK solely to integrate Your Platform with the Company Platform or the SDK; and (b) modify any sample code included within the SDK solely as necessary to develop integration code necessary to integrate Your Platform and the Company Platform or the SDK.
Restrictions. You will not: (a) modify or delete any copyright, trademark, or other proprietary notices of Company or its licensors in the SDK; (b) reverse engineer, decompile, disassemble, or otherwise tamper with the SDK (except to the extent that any such restrictions are prohibited by applicable law); (c) modify any of the APIs specified in the SDK or object code libraries included with the SDK; or (d) assert (or authorize, assist, or encourage any third party to assert) any intellectual property infringement claim against Company or any of its affiliates, customers, or licensees regarding any portions of the SDK you have used. Except with Company’s prior written permission, you may not use Company APIs other than as documented in the SDK.
Company Marks. You acknowledge and agree that the words “Mercedes-Benz,” “Mercedes,” “Maybach,” “Smart,” “RideScout,” “Ride.Kit” and the Three-Pointed Star Within a Circle, the Maybach logo, the Smart logo, and the RideScout logo are the solely owned and validly registered trademarks and trade names of Daimler AG, the indirect parent company of RideScout LLC.  You recognize that it is not authorized to use any of Daimler AG’s trademarks and trade names without prior written approval of Ridescout. 
IP Rights. The Agreement does not: (a) provide you with any right or license (whether expressly, by implication, by estoppel, or otherwise) under any of Company’s intellectual property rights other than to use, create derivative works of, reproduce, and distribute the SDK and the Company Marks solely in the manner and solely to the extent authorized in sections 2.1and 2.3; or (b) impair the right of Company to develop, make, use, procure, protect, and/or market any products or services which are competitive with Your Platform. Company reserves all rights not expressly granted to you.
Modifications to the SDK. Except for sample code included in the SDK, you may not make any modifications to the SDK. As between you and Company, and subject to Company’s ownership of the SDK, you will own Your Platform and any SDK Modifications. You may only license or distribute SDK Modifications as part of Your Platform. You will provide all SDK Modifications to Company and you hereby grant Company a perpetual, irrevocable, non-exclusive, royalty-free, and worldwide license to reproduce, create derivative works from, distribute, publicly display, publicly perform, make, have made, offer for sale, sell or otherwise dispose of, import, use, and otherwise commercialize the SDK Modifications in connection with Company’s products and services, with the right to sublicense each and every right. 
Changes. Company reserves the right, at any time, to change the features and functionality of the SDK and the Company Platform without liability to you. Such changes might include, without limitation, disabling APIs or limiting API calls. Company will use commercially reasonable efforts to provide you with prior notice of such changes. If you do not agree to the changes, your sole course of action will be to stop using the SDK and terminate this agreement. 
Data Rights. 
Rights in Customer Data.  If you elect to transfer Customer Data to Company, you represent and warrant that you have the right to freely transfer to Company any Customer Data submitted to you.  You hereby grant Company a non-exclusive, royalty-free, irrevocable, worldwide right and license, with right to sublicense, to access, store, transfer, use, modify, and otherwise process any and all Customer Data you make accessible to Company. You are under no obligation to transfer Customer Data.  
Disclosure or Transfer of Customer Data.  You will comply with the terms of this Agreement and of your privacy policy if you transfer Customer Data, or any data you obtain through or in connection with the Company Platform, to any third party.  Where required under applicable law, your privacy policy, or under the terms of any relevant agreement, you will provide notice and choice to the individual about whom such data relates prior to such data transfer or disclosure.  
Data Security.  You represent and warrant that you provide reasonable and appropriate administrative, technical and operational measures to ensure reasonable security for all Customer Data and data obtained from or in connection with the Company platform.  If requested by Company, you agree to encrypt any data you obtain in connection with this Agreement.  You will have in place an information security incident management program that addresses management of information security incidents and system weaknesses, including without limitation: 1) any loss, theft, misuse of or unauthorized access, disclosure or destruction of any data; and 2) any violations or potential violations of federal or state law.  You will provide Company with immediate notice of any such data security incident (including events described in the preceding sentence) involving or potentially involving data transferred in connection with this Agreement (each such event, an “Incident”).  You will cooperate fully with Company to resolve and respond to any Incident or suspected Incident.  Except as required by law, you will not notify affected parties, regulators or other third parties regarding any Incident without prior consultation with Company.
Data Protection Compliance.  You represent and warrant that your use of the API and SDK complies with all applicable laws, including those related to data privacy, data security, and international communications and that you have obtained any and all consents necessary for you and Company to engage in data processing under this Agreement.  Submission or provision of Customer Data to Company will be at your own risk, and Company assumes no responsibility or liability for receipt of such Customer Data.  
EU Data; Data Controller and Data Processor Relationship.  If you collect, access, use, or otherwise process personal data originating or collected from the European Economic Area and Switzerland, you will adhere to and comply with the safe harbor principles developed by the Department of Commerce in coordination with the European Commission and Switzerland (the “US Safe Harbor”).  If you cannot adhere to the US Safe Harbor for any reason (including non-applicability of the US Safe Harbor to your business), you will promptly execute the necessary documents containing the clauses contained in the model contracts for the transfer of personal data to third countries, as issued by the European Commission pursuant to Directive 95/46/EC of the European Parliament and of the Council of 24 October 1995 on the protection of individuals with regard to the processing of personal data and on the free movement of such data (the “EU Directive”) to the extent, as determined in Company’s sole discretion, you may be deemed a data processor under the EU Directive with respect to any data for which Company may be deemed a data controller under the EU Directive.
Compelled Disclosure. If you are compelled by law to disclose Customer Data or data you obtained through the Company Platform, you will: (a) provide Company with prior notice of such compelled disclosure (to the extent legally permitted) and reasonable assistance, at your cost, if you or Company wishes to contest the disclosure; (b) disclose only the minimum amount of data requested; and (c) take reasonable steps to ensure that the disclosure does not result in further disclosure of the requested information to improper or unauthorized parties or the public
Development and Distribution of Your Platform. 
Guidelines. Your Platform must:
comply with any guidelines set forth in the developer’s guide included with or referenced in the SDK, as updated from time to time;
comply with any applicable laws, rules, or regulations; 
not contain any viruses or other malicious code or instructions that may be used to access, modify, delete, damage, or disable the Company Platform or any other Company software; and
not disrupt, interfere with, or access in an unauthorized manner the Company Platform or any Company software or servers.
Compliance: In connection with this Agreement, You are obliged to desist from all practices which may lead to penal liability due to fraud or embezzlement, insolvency crimes, crimes in violation of competition, guaranteeing advantages, bribery, acceptance of bribes or other corruption crimes on the part of persons employed by You or other third parties.  In the event of violation of the above, Ridescout has the right to immediately withdraw from or terminate all transactions existing with You.
Customer Obligations. Your Platform must be licensed to Customers pursuant to a written agreement that, at a minimum:
obtains opt-in consent from end users prior to the collection and use of their personal information; and
includes a privacy policy that is compliant with all applicable laws and regulations and authorizes the sharing of data with Company.
Support. You will be solely responsible for any Customer support and warranty of Your Platform. 
Access. Company may (in its reasonable discretion) suspend Your Platform’s access to the Company Platform and SDK at any time if Company believes that (a) you are in breach of any obligations under the Agreement; (b) Your Application poses a security risk; (c) there is a bug or performance issue with Your Platform; (d) Your Platform violates, misappropriates, or infringes the rights of Company or a third party; or (e) Your Platform imposes unexpected or excessive demands on the Company Platform.
Open Source. Certain components of the SDK may be covered by open source software (“OSS”) licenses. To the extent required by the license for any OSS: (a) the terms of such license will apply to such OSS instead of the terms of the Agreement; and (b) any restrictions prohibited by such license that are contained in the Agreement will not apply to such OSS.
Feedback. Any feedback from You to Company is subject to any pre-existing Confidentiality Agreements. Such agreements remain in full effect. Company disclaims any use restrictions related to any information or materials that you may provide to Company related to the SDK or Company Platform. 
Term and Termination. 
Term. The term of the Agreement will commence on the Effective Date and continue until terminated in accordance with section 7.2. 
Termination. Either you or Company may terminate the Agreement at any time by sending notice to the other party. 
Effects of Termination. Upon termination of the Agreement: (i) Company will immediately disable Your Platform’s access to the Company Platform; and (ii) you will immediately cease using the SDK and delete all copies you have in your possession or under your control. This section and sections 2.2, 2.4, 3.6, 6, 7.3 and 8-12 will survive termination of the Agreement.
Confidentiality. 
General Obligation. Each party, as a recipient of Confidential Information, will (a) hold the disclosing party’s Confidential Information in strict confidence; (b) protect and safeguard the confidentiality of the disclosing party’s Confidential Information with at least the same degree of care as it protects and safeguards its own confidential and proprietary information (but in no event with less than a reasonable degree of care); (c) immediately notify the disclosing party of any unauthorized access, use, or disclosure of any of its Confidential Information; and (d) cooperate with the disclosing party’s efforts to prevent further breaches of the Agreement. 
Disclosure to Representatives. In addition to the obligations in section 8.1, the receiving party will only disclose or disseminate the disclosing party’s Confidential Information to its employees and contractors (“Representatives”) who have a need to know and who have signed written agreements with (or are otherwise bound by confidentiality obligations owed to) the receiving party that require or permit such individuals to use, disclose, and protect the disclosing party’s Confidential Information only in a manner consistent with the provisions of the Agreement. The receiving party will be liable to the disclosing party for any failure by any Representatives to comply with obligations set forth in the Agreement.
Press Releases. You may not issue any press releases or make any other public statements about the Agreement without Company’s prior written approval.
Disclaimer of Warranties. COMPANY IS PROVIDING YOU WITH THE SDK “AS IS” WITHOUT WARRANTIES OF ANY KIND, AND YOUR USE OF THE SDK IS AT YOUR OWN RISK. TO THE GREATEST EXTENT PERMITTED BY LAW, COMPANY AND ITS LICENSORS EXPRESSLY DISCLAIM ANY AND ALL WARRANTIES, WHETHER EXPRESS OR IMPLIED, INCLUDING ANY WARRANTIES REGARDING ACCURACY, OPERABILITY, USE, NON-INFRINGEMENT, TITLE, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
Limitation of Liability. EXCEPT WITH RESPECT TO BREACHES OF SECTIONS 3 OR 8 OR INDEMNIFICATION OBLIGATIONS, AND TO THE GREATEST EXTENT PERMITTED BY LAW, NEITHER PARTY WILL BE LIABLE TO THE OTHER PARTY UNDER ANY THEORY OF LIABILITY FOR ANY INDIRECT, INCIDENTAL, CONSEQUENTIAL, SPECIAL, OR EXEMPLARY DAMAGES (EVEN IF SUCH PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES AND/OR SUCH DAMAGES ARE FORESEEABLE) ARISING OUT OF OR RELATED TO THE AGREEMENT, INCLUDING, BUT NOT LIMITED TO, ANY LOSS OF REVENUE OR ANTICIPATED PROFITS OR LOST BUSINESS. IN NO EVENT WILL COMPANY’S LIABILITY TO YOU OR YOUR CUSTOMERS ARISING OUT OF OR RELATED TO THE AGREEMENT EXCEED $2,500.00. 
Indemnification. To the greatest extent permitted by law, you will indemnify, defend, and hold harmless Company and its officers, directors, employees, and agents from and against any and all third party claims, demands, damages, liabilities, costs, and expenses (including reasonable attorneys’ fees and court costs) arising out of or related to: (a) your mis-use of the SDK; (b) the use by any third party of Your Platform; and (c) your breach of the Agreement. Company will use commercially reasonable efforts to provide you with prompt notification of any claim for which Company seeks an indemnity, but Company’s failure to provide such prompt notice will not limit your obligation to indemnify Company unless you have been materially harmed by such failure of prompt notice. Company will cooperate in your defense of any claim, at your sole expense. You may not settle any claim against Company in a manner that adversely affects Company without Company’s prior written consent, which consent will not be unreasonably withheld, conditioned or delayed. Company may participate in the defense of a claim through counsel of its own choice at its own expense; provided, however, that if Company reasonably determines that you are unwilling or unable to defend the interests of Company, then Company may assume the defense against any claims at your expense. Company will not settle any claim for which you are obligated to indemnify Company without your prior written consent, which consent will not be unreasonably withheld, conditioned or delayed). 
General Legal Terms.
Assignments. You may not assign or transfer the Agreement (or any of your rights or obligations under the Agreement) without (a) Company’s prior written consent, and (b) where consent has been granted, by ensuring that any assignee or transferee agrees to be bound by the Agreement in the same manner as you (including with respect to any intellectual property rights). Any attempted assignment or transfer without complying with the preceding sentence will be void. Company may freely assign or transfer the Agreement. The Agreement inures to the benefit of and is binding upon the parties and their respective legal representatives, successors, and permitted assigns. 
Authority. If you are using the SDK on behalf of your employer or for your employer’s products, you represent, warrant and covenant that you have the right, power and authority to enter into the Agreement on behalf of your employer.
Electronic Communications. You consent to receive communications from Company electronically. Company will communicate with you by email, and you acknowledge that all agreements, notices, disclosures and other communications that Company provides to you electronically will satisfy any legal requirement that such communications be in writing.
Entire Agreement; Amendments. Except as specifically stated, this Agreement supersedes all prior discussions and writings regarding (and constitutes the entire agreement between the parties with respect to the SDK and the Company Platform. The parties may only amend the Agreement in writing. 
Export. You will not (whether directly or indirectly) export or re-export the SDK to: (a) any countries that are subject to US export restrictions (such as, by way of example and not limitation, Iran, North Korea, Sudan, and Syria); (b) any third party who will utilize the SDK for prohibited end uses (such as, by way of example and not limitation, for the design, development or production of nuclear, chemical or biological weapons); or (c) any third party who has been prohibited from participating in U.S. export transactions by any federal agency of the U.S. government (such as someone on the U.S. Treasury Department's list of Specially Designated Nationals or the U.S. Department of Commerce Denied Persons List or Entity List). 
Governing Law and Venue. The Agreement is to be governed by and construed in accordance with the laws of the United States and the State of Texas, excluding its conflict of law principles. You and Company will: (a) bring any disputes arising out of or related to the Agreement exclusively in a state or federal court located in Austin, TX; and (b) submit to the personal jurisdiction of such courts.
Notices. To be valid, all notices permitted or required under the Agreement must be sent in writing by a party as follows (unless a party changes such information by giving notice in accordance with this section): (a) if to you, by Company via email to the address associated with your developer account, and (b) if to Company, by you via certified mail to Ridescout, LLC, 200 E. 6th Street, Suite 200 Austin, TX 78701, attn.: Legal Department. Notices will be deemed given (a) if to you, when emailed, and (b) if to Company, on receipt by Company.
Relationship. The Agreement does not confer any third party beneficiary rights and does not create a joint venture, agency, partnership, or other form of joint enterprise between the parties. Except as expressly provided herein, neither party has the right, power, or authority to create any obligation or duty, express or implied, on behalf of the other. There are no intended third party beneficiaries of the Agreement.
Severability, Waiver, and Interpretation. If any provision of the Agreement is found to be unenforceable or invalid, such unenforceability or invalidity will not render the Agreement unenforceable or invalid as a whole and, in such event, such provision is to be changed and interpreted so as to best accomplish the objectives of such unenforceable or invalid provision within the limits of applicable law. No waiver of any breach of the Agreement will constitute a waiver of any other breach. In construing or interpreting the terms of the Agreement: (a) the headings in the Agreement are for convenience only, and are not to be considered, and (b) no presumption is to operate in either party’s favor as a result of its counsel’s role in drafting the Agreement.
Representation by Counsel. You represent that you have had the opportunity to review the Agreement with legal counsel of your choosing prior to entering into the Agreement even if you have chosen not to seek such counsel.