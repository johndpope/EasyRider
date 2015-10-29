//
//  RKProvider.h
//  Ride.Kit
//
//  Created by Brady Miller on 1/27/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>

@class  RKFeature;

/**
 The RKProvider class declares the programmatic interface methods for creating an instance of RKProvider
 */
@interface RKProvider : NSObject

/// @name Properties

/**
 @brief The name of the provider.
 */
@property (nonatomic, strong) NSString *name;

/**
 @brief The ride type of the provider.
 */
@property (nonatomic, strong) NSNumber *rideType;

/**
 @brief The bundle id for the provider.
 */
@property (nonatomic, strong) NSString *bundleId;

/**
 @brief The version number for the RKProvider to ensure versioning.
 */
@property (nonatomic, strong) NSString *versionNumber;

/**
 @brief The url for the provider's icon.
 */
@property (nonatomic, strong) NSString *iconURL;

/**
 @brief The URL scheme of the orivuder so that the app can be opened for firing off RKFeatures.
 */
@property (nonatomic, strong) NSString *urlScheme;

/**
 @brief The iOS App Store URL so that the App Store can be opened to download the app.
 */
@property (nonatomic, strong) NSString *appStoreURL;

/**
 @brief An array of RKFeature objects that are available for this provider.
 */
@property (nonatomic, strong) NSArray *features;

/**
 @brief An array of RKRide objects for this provider.
 @warning This will be empty unless the app has received the data via the getRidesNearbyForLatitude:andLongitude:completion:(void (^)(NSArray *providers))completion method defined in RideKitManager.
 */
@property (nonatomic, strong) NSArray *rides;

/// @name Creating an RKProvider

/**
 @brief Init method that parses the provider dictionary and returns a provider instance.
 @param providerDictionary A dictionary for which the RKProvider will draw the data.
 @return An instance of RKProvider with the data from the providerDictionary.
 */
- (instancetype)initWithProviderDictionary:(NSDictionary *)providerDictionary;

/**
 @brief Convenience method for parsing a provider dictionary and creating a provider object.
 @param providerDictionary A dictionary for which the RKProvider will draw the data.
 */
- (void)parseProviderDicionary:(NSDictionary *)providerDictionary;

@end
