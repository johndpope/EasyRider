//
//  RKFeature.h
//  Ride.Kit
//
//  Created by Brady Miller on 1/27/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Used to determine the functionality of the RKFeature.
typedef NS_ENUM(int, RKFeatureType) {
    /// Undefined feature type.
    RKFeatureTypeUndefined = -1,
    
    /// A search that returns rides near a location.
    RKFeatureTypePointSearch = 0,
    
    /// A search that returns trips from A to B.
    RKFeatureTypeABSearch = 1,
    
    /// Get an existing booking.
    RKFeatureTypeBookingGetExisting = 2,
    
    /// Create a booking.
    RKFeatureTypeBookingCreate = 3,
    
    /// Delete a booking.
    RKFeatureTypeBookingDelete = 4,
    
    /// Get an existing ticket.
    RKFeatureTypeTicketGetExisting = 5,
    
    /// Purchase a ticket.
    RKFeatureTypeTicketPurchase = 6,
    
    /// Get info.
    RKFeatureTypeGetInfo = 7,
};

/**
 The RKFeature class declares the programmatic interface methods for creating an instance of RKFeature, and convenience methods for getting UI details and firing off the feature.
 */
@interface RKFeature : NSObject

/// @name Properties

/**
 @brief The name of the feature.
 */
@property (nonatomic, strong) NSString *name;

/**
 @brief The RKFeatureType for the feature.
 */
@property (nonatomic, assign) RKFeatureType type;

/**
 @brief The url scheme for this feature to launch the feature's app.
 */
@property (nonatomic, strong) NSString *urlScheme;

/**
 @brief The callback url scheme so that the other iOS application in the Ride.Kit Network that executes an RKFeature knows where to return after executing.
 */
@property (nonatomic, strong) NSString *callbackUrlScheme;

/**
 @brief A dictionary that contains the parameters for this feature for the other iOS application in the Ride.Kit Network to execute this feature.
 */
@property (nonatomic, strong) NSDictionary *parameters;

/**
 @brief The integrator must implement the requestHandler when creating an RKFeature to handle the execution of a feature.
 */
@property (nonatomic, copy) void (^requestHandler)(NSDictionary *parameters);

/**
 @brief A dictionary that contains the results for the executed feature.
 */
@property (nonatomic, strong) NSDictionary *result;

/**
 @brief The application firing off a feature must implement the responseHandler to handle the results of a feature.
 */
@property (nonatomic, copy) void (^responseHandler)(NSDictionary *results);

/// @name Creating an RKFeature

/**
 @brief Init method with name and type.
 @param name The name of the feature.
 @param type The type for the feature.
 @param requestHandler The completion block that is the handler for executing this feature.
 @return An instance of RKFeature with the name and type data.
 */
- (instancetype)initWithName:(NSString *)name type:(RKFeatureType)type andRequestHandler:(void (^)(NSDictionary *parameters))requestHandler;

/// @name Convenience

/**
 @brief Convenience method for building a provider feature from a JSON object.
 @param featureDictionary A dictionary used to build a RKFeature object from the dictionary of key value pairs.
 */
+ (RKFeature *)buildProviderFeatureFromDictionary:(NSDictionary *)featureDictionary;

/**
 @brief Convenience method for creating a dictionary from this instance of an RKFeature so that we can send it up to the backend.
 */
- (NSDictionary *)buildProviderFeatureDictionary;

@end
