//
//  RKProfile.h
//  RideKit
//
//  Created by Brady Miller on 6/3/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The RKProfile class declares the programmatic interface methods for creating an instance of RKProfile and accessing any information available for the logged in user.
 */
@interface RKProfile : NSObject

/// @name Properties

/**
 @brief The first name of the user.
 */
@property (nonatomic, strong) NSString *firstName;

/**
 @brief The last name of the user.
 */
@property (nonatomic, strong) NSString *lastName;

/**
 @brief The email for the user.
 */
@property (nonatomic, strong) NSString *email;

/**
 @brief The phone number for the user.
 */
@property (nonatomic, strong) NSString *phoneNumber;

/**
 @brief The url for the image of the user.
 */
@property (nonatomic, strong) NSURL *imageUrl;

/**
 @brief The home address for the user.
 */
@property (nonatomic, strong) NSString *homeAddress;

/**
 @brief The work address for the user.
 */
@property (nonatomic, strong) NSString *workAddress;

/// @name Creating an RKProfile

/**
 @brief Init method that parses the profile dictionary and returns an RKProfile.
 @param profileDictionary A dictionary that contains the data that came from the Ride.Kit Network for the user's Ride.Kit profile.
 @return An instance of RKProfile with the data from the profileDictionary.
 */
- (instancetype)initWithProfileDictionary:(NSDictionary *)profileDictionary;

@end
