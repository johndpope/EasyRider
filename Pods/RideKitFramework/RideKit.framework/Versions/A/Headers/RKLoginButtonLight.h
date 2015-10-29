//
//  RKLoginButtonLight.h
//  Ride.Kit
//
//  Created by Brady Miller on 6/9/15.
//  Copyright (c) 2015 RideScout. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 The RKLoginButtonLight is a UIButton subclass that you can add to your application to automatically integrate Ride.Kit login for dark backgrounds. All you have to do is implement the loggedInWithAccessToken: of the RideKitDelegate in order to implement login.
 */

@interface RKLoginButtonLight : UIButton

@end
