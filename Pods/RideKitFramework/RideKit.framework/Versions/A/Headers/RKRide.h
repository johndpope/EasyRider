//
//  RKRide.h
//  Ride.Kit
//
//  Created by Brady Miller on 5/18/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 The RKRide class declares the programmatic interface methods for creating an instance of RKRide.
 */
@interface RKRide : NSObject

/// @name Properties

/**
 @brief The provider id of the ride.
 */
@property (nonatomic, strong) NSString *providerId;

/**
 @brief The position id of the ride.
 */
@property (nonatomic, strong) NSString *positionId;

/**
 @brief The location of the ride.
 */
@property (nonatomic, strong) CLLocation *location;

/**
 @brief A float that is the distance from the ride.
 */
@property (nonatomic, strong) NSNumber *distance;

/**
 @brief A dictionary that contains the details for the ride.
 */
@property (nonatomic, strong) NSDictionary *detailsDictionary;

/**
 @brief The query type of the ride. This can be 'apifeedquery', 'transit', or 'geoptwithradiusquery'
 */
@property (nonatomic, strong) NSString *queryType;

/// @name Creating an RKRide

/**
 @brief Init method that parses the ride dictionary and returns a ride instance.
 @param rideDictionary A dictionary that contains the data that came from the getRidesNearbyForLatitude:andLongitude:completion:(void (^)(NSArray *providers))completion method defined in RideKitManager.
 @return An instance of RKRide with the data from the rideDictionary.
 */
- (instancetype)initWithRideDictionary:(NSDictionary *)rideDictionary;

@end
