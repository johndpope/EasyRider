//
//  RKLoginManager.h
//  Ride.Kit
//
//  Created by Brady Miller on 5/20/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RKProfile;

/** 
 The RKLoginManager class declares the programmatic interface for logging into the Ride.Kit Network with the RKLoginButtonDark, RKLoginButtonLight, or your own custom login button. To implement your own custom login buttom called getRideScoutAccessTokenAndLogin class method. Both implementations require loggedInWithProfile from the RideKitManagerDelegate if you want to receive the RKProfile object. 
 */
@interface RKLoginManager : NSObject

/// Login methods

/**
 @brief Retrieves the access token from RideScout if the user has the app installed, otherwise
 retrieves the code from the UIWebView to log in the user.
 */
+ (void)getRideScoutAccessTokenAndLogin;

/**
 @brief Logs the user in with either the access token, or the code depending on which is given.
 @param token Optional if the user is to be logged in via an access token.
 @warning This method does not need to be called by the implementer as it is done automatically by the SDK. Either the token or code need to be sent to log in.
 */
+ (void)loginWithAccessToken:(NSString *)token;

/**
 @brief Logs the user in with the email and password.
 @param email The email address for the user's account.
 @param password The password for the user's account.
 */
+ (void)loginWithEmail:(NSString *)email andPassword:(NSString *)password;

/**
 @brief Sends an email to reset the user's password.
 @param email The email address for which to send the reset password email.
 */
+ (void)forgotPasswordForEmail:(NSString *)email;

@end
