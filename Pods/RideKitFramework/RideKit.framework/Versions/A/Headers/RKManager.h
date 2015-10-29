//
//  RKManager.h
//  Ride.Kit
//
//  Created by Brady Miller on 5/8/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#define RIDESCOUT_API_URL @"http://sdk.ridescout.appspot.com/"
#define SDK_API_URL @"http://beta.gateway.ridescout.com/"
//#define SDK_API_URL @"http://sdk.ridescout.appspot.com/"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RKFeature.h"

@class RKConfiguration;
@class RKProfile;
@class RKProvider;

/**
 The delegate for the Ride.Kit SDK. The delegate handles executing features and retrieving their results along with logging into the Ride.Kit Network.
 */
@protocol RideKitDelegate <NSObject>

/**
 @brief Sends the access token to the calling app for login purposes.
 @param profile The RKProfile object that has all the user's available information.
 */
@optional
- (void)loggedInWithProfile:(RKProfile *)profile;

@end

/**
 The RKManager class declares the programmatic interface for iOS applications to communicate via inter-app communication to other iOS applications in the Ride.Kit Network. The instance methods in this class should be called using the sharedService which is a singleton instance of the RKManager class.
 */
@interface RKManager : NSObject

/// @name Properties

/**
 @brief The API key that the developer must acquire from www.ridescout.com
 */
@property (nonatomic, strong) NSString *apiKey;

/**
 @brief The custom URL scheme defined in the Info.plist.
 @warning If the callbackUrlScheme does not open the current app then an NSAssert will fail.
 */
@property (nonatomic, strong) NSString *callbackUrlScheme;

/**
 @brief The RKProviders that are returned by the Ride.Kit Network.
 */
@property (nonatomic, strong) NSArray *providers;

/**
 @brief The RKFeatures that are returned by the Ride.Kit Network.
 */
@property (nonatomic, strong) NSArray *features;

/**
 @brief Delegate that is needed in order to implement the RideKitDelegate methods.
 */
@property (nonatomic, weak) id<RideKitDelegate> delegate;

/// @name Accessing and starting the Ride.Kit singleton

/**
 @brief Returns the singleton instance for the RKManager
 @return A RKManager singleton instance of the Ride.Kit class.
 */
+ (RKManager *)sharedService;

/**
 @brief Starts the Ride.Kit SDK with the RKConfiguration and retrieves the RKProviders in the Ride.Kit network.
 @param configuration The configuration which includes the api key, callback, and the list of RKFeature objects.
 @param completion The completion block that returns the providers from the Ride.Kit Network.
 */
- (void)startRideKitWithConfiguration:(RKConfiguration *)configuration completion:(void (^)(NSArray *providers))completion;

/// @name RKFeature handlers

/**
 @brief Checks if the url came from the Ride.Kit Network and if so grabs the message that was sent and sends it to the right RideKitDelegate method.
 @param url Used to open the application.
 @return YES if the URL came from the Ride.Kit SDK and NO if it came from somewhere else.
 */
- (BOOL)handleOpenURL:(NSURL *)url;

/**
 @brief Returns an array of RKProvider objects.
 @param lat The latitude of the location for which to return rides
 @param lng The longitude of the location for which to return rides
 @param completion The completion block that will send the array of RKProvider objects upon completion.
 */
- (void)getRidesNearbyForLatitude:(double)lat andLongitude:(double)lng completion:(void (^)(NSArray *providers))completion;

/// @name SDK Actions

/**
 @brief Executes the RKFeature which will launch the target app with x-callback.
 @param feature The feature that is to be executed.
 @param results The handler for the results of a feature execution.
 */
- (void)executeFeature:(RKFeature *)feature withResultsHandler:(void (^)(NSDictionary *results))results;

/**
 @brief Executes the RKFeature which will launch the target app with x-callback.
 @param feature The feature that is to be executed.
 @param parameters The parameters for the execution of the feature.
 @param results The handler for the results of a feature execution.
 */
- (void)executeFeature:(RKFeature *)feature withParameters:(NSDictionary *)parameters andResultsHandler:(void (^)(NSDictionary *results))results;

/**
 @brief Returns the RKFeature with the results to the app who fired off the feature.
 @param resultsDictionary The results for the feature that was fired off.
 */
- (void)returnResults:(NSDictionary *)resultsDictionary;

/// @name Convenience

/**
 @brief Convenience method for turning the JSON respone for the rides nearby from the Ride.Kit API to an array of RKProvider objects.
 @param providersDictionary The JSON response from Ride.Kit via getRidesNearbyForLatitude:andLongitude:completion:
 @return An array of RKProvider objects built from the providersDictionary
 @see getRidesNearbyForLatitude:andLongitude:completion:
 */
- (NSArray *)getProvidersFromResultsDictionary:(NSDictionary *)providersDictionary;

/**
 @brief Convenience method to get the providers of the specified ride type.
 @param rideType The ride type of the desired providers.
 @return An array of RKProvider objects that are of the specified type.
 */
- (NSArray *)getProvidersWithRideType:(NSNumber *)rideType;

/**
 @brief Convenience method to get the providers that have features with the specified type.
 @param type The feature type for the providers.
 @return An array of RKProvider objects that implement an RKFeature with type.
 */
- (NSArray *)getProvidersWithFeatureType:(RKFeatureType)type;

/**
 @brief Convenience method to get the features with the specified type.
 @param type The feature type for the features.
 @return An array of RKFeature objects that are of the specified type.
 */
- (NSArray *)getFeaturesForProvidersWithFeatureType:(RKFeatureType)type;

/**
 @brief Convenience method for getting the features for a specific provider
 @param name The name of the provider that you want features from.
 @return An array of RKFeature objects for the provider with the specified name.
 */
- (NSArray *)getFeaturesForProviderWithName:(NSString *)name;

/**
 @brief Convenience method for getting the features from providers with the specified ride type.
 @param rideType The ride type of the provider that you want features from.
 @return An array of RKFeature objects for the provider with the specified ride type.
 */
- (NSArray *)getFeaturesForProviderWithRideType:(NSNumber *)rideType;

/**
 @brief Convenience method for getting the provider that contains the specified feature
 @param feature The feature for which we are looking for the associated provider.
 @return The RKProvider associated with the feature, nil if not found.
 */
- (RKProvider *)getProviderWithFeature:(RKFeature *)feature;

@end
