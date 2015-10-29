//
//  RKConfiguration.h
//  RideKit
//
//  Created by Brady Miller on 6/15/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The RKConfiguration class declares the programmatic interface methods for creating an instance of RKConfiguration which declares the configuration of this app and is to be sent to the singleton instance of RideKit via the startRideKitWithConfiguration:completion: method.
 */
@interface RKConfiguration : NSObject

/// @name Properties

/**
 @brief The API key that the developer must acquire from www.ridescout.com
 */
@property (nonatomic, strong) NSString *apiKey;

/**
 @brief The custom URL scheme defined in the Info.plist.
 @warning If the callbackUrlScheme cannot open the current app then an NSAssert will fail.
 */
@property (nonatomic, strong) NSString *callbackUrlScheme;

/**
 @brief The RKFeatures that will be sent up to the Ride.Kit Network.
 */
@property (nonatomic, strong) NSArray *features;

/**
 @brief The latitude for the feature filter.
 */
@property (nonatomic, assign) double lat;

/**
 @brief The longitude for the feature filter.
 */
@property (nonatomic, assign) double lng;

/// @name Creating an RKConfiguration

/**
 @brief Creates a configuration object with the api key, callback url scheme, and the array of RKFeatures.
 @param apiKey The api key that has been retrieved from the Ride.Kit Hub.
 @param callbackUrlScheme The custom URL Scheme set so that other applications in the Ride.Kit Network can launch this app's features.
 @param features An array of RKFeatures that this app implements.
 @warning If the callbackUrlScheme does not open the current app then an NSAssert will fail.
 */
- (instancetype)initWithApiKey:(NSString *)apiKey callbackUrlScheme:(NSString *)callbackUrlScheme andFeatures:(NSArray *)features;

/**
 @brief Creates a configuration object with the api key, callback url scheme, and the array of RKFeatures.
 @param apiKey The api key that has been retrieved from the Ride.Kit Hub.
 @param callbackUrlScheme The custom URL Scheme set so that other applications in the Ride.Kit Network can launch this app's features.
 @param features An array of RKFeatures that this app implements.
 @param lat The latitude for the feature filter.
 @param lng The longitude for the feature filter.
 @warning If the callbackUrlScheme does not open the current app then an NSAssert will fail.
 */
- (instancetype)initWithApiKey:(NSString *)apiKey callbackUrlScheme:(NSString *)callbackUrlScheme andFeatures:(NSArray *)features withlat:(double)lat andLng:(double)lng;

@end
