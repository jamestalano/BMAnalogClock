//
//  BMAnalogClockView.h
//  BMAnalogClockView
//
//  Created by James Talano on 2/23/14.
//  Copyright (c) 2014 James Talano. All rights reserved.
//

#if __has_feature(objc_modules)
    // We recommend enabling Objective-C Modules in your project Build Settings for numerous benefits over regular #imports. Read more from the Modules documentation: http://clang.llvm.org/docs/Modules.html
    @import Foundation;
    @import UIKit;
    @import CoreGraphics;
#else
    #import <Foundation/Foundation.h>
    #import <UIKit/UIKit.h>
    #import <CoreGraphics/CoreGraphics.h>
#endif

#import "KSMHand.h"

@protocol BMAnalogClockDelegate;

IB_DESIGNABLE
/// BMAnalogClock is an UIView subclass that gives you an easy way to create beautiful, interactive analog clocks for iOS.
@interface BMAnalogClockView : UIView <UIGestureRecognizerDelegate>


//------------------------------------------------------------------------------------//
//----- DELEGATE ---------------------------------------------------------------------//
//------------------------------------------------------------------------------------//

/// BMAnalogClockView delegate object is essential to the clock. The delegate provides the clock with data and various parameters. The delegate can be set from the interface or from code.
@property (nonatomic, assign) IBOutlet id <BMAnalogClockDelegate> delegate;


//------------------------------------------------------------------------------------//
//----- PROPERTIES -------------------------------------------------------------------//
//------------------------------------------------------------------------------------//

/// The hours property. Used to set up the hour hand. Default value is 10.
@property (nonatomic, assign) NSInteger hours;

/// The minutes property. Used to set up the minute hand. Default value is 10.
@property (nonatomic, assign) NSInteger minutes;

/// The seconds property. Used to set up the second hand. Default value is 0.
@property (nonatomic, assign) NSInteger seconds;

/// If set to YES, the hands will cast a shadow. Default value is YES.
@property (nonatomic) IBInspectable BOOL enableShadows;

/// If set to YES, the graduation on the clock will be visible. See the methods bellow to costumize the graduations. Default value is YES.
@property (nonatomic) IBInspectable BOOL enableGraduations;

/// If set to YES, the digits (1-12) will be displayed on the face of the clock. Default value is NO.
@property (nonatomic) IBInspectable BOOL enableDigit;

/// If set to YES, a circular hub will be drawn. Default value is NO;
@property (nonatomic) IBInspectable BOOL enableHub;

/// If set to YES, the clock will be updated in real time (the second hand will move every second, the minute hand every minute...). Default value is NO;
@property (nonatomic) BOOL realTime;

/// If set to YES, the clock will be set to the current time on the phone. Prioritized over setting the time manualy. Default value is NO.
@property (nonatomic) BOOL currentTime;

/// If set to YES, the clock time can be updated via touch inputs. Default value is NO.
@property (nonatomic) BOOL setTimeViaTouch;

/// If set to YES, the clock time will suport military time. Default value is NO.
@property (nonatomic) IBInspectable BOOL militaryTime;

/// If set to YES, the clock real time feature is activated. Read only.
@property (readonly, nonatomic) BOOL realTimeIsActivated;


//----- CLOCK'S FACE CUSTOMIZATION -----//

/// The background color of the clock's face.
@property (strong, nonatomic) IBInspectable UIColor *faceBackgroundColor;

/// The alpha of the clock's face.
@property (nonatomic) IBInspectable CGFloat faceBackgroundAlpha;

/// The color of the clock's border.
@property (strong, nonatomic) IBInspectable UIColor *borderColor;

/// The alpha of the clock's border.
@property (nonatomic) IBInspectable CGFloat borderAlpha;

/// The width of the clock's border.
@property (nonatomic) IBInspectable CGFloat borderWidth;

/// The font of the digits appearing inside the clock
@property (strong, nonatomic) IBInspectable UIFont *digitFont;

/// The color of the digits appearing inside the clock
@property (strong, nonatomic) IBInspectable UIColor *digitColor;

/// The offset for the position of the digits on the clock's face. A value >0 will make the digits appear further away from the center of the clock. A valut <0 will make them closer to the center of the clock. Default value is 0.0.
@property (nonatomic) IBInspectable CGFloat digitOffset;


//----- HOURS HAND CUSTOMIZATION -----//

/// The color of the clock's hour hand. Default value is whiteColor.
@property (strong, nonatomic) IBInspectable UIColor *hourHandColor;

/// The alpha of the clock's hour hand. Default value is 1.0.
@property (nonatomic) IBInspectable CGFloat hourHandAlpha;

/// The width of the clock's hour hand. Default value is 4.0.
@property (nonatomic) IBInspectable CGFloat hourHandWidth;

/// The length of the clock's hour hand. Default value is 30.
@property (nonatomic) IBInspectable CGFloat hourHandLength;

/// The length of the offside part of the clock's hour hand. Default value is 10.
@property (nonatomic) IBInspectable CGFloat hourHandOffsideLength;


//----- MINUTES HAND CUSTOMIZATION -----//

/// The color of the clock's minute hand. Default value is whiteColor.
@property (strong, nonatomic) IBInspectable UIColor *minuteHandColor;

/// The alpha of the clock's minute hand. Default value is 1.0.
@property (nonatomic) IBInspectable CGFloat minuteHandAlpha;

/// The width of the clock's minute hand. Default value is 3.0.
@property (nonatomic) IBInspectable CGFloat minuteHandWidth;

/// The length of the clock's minute hand. Default value is 55.
@property (nonatomic) IBInspectable CGFloat minuteHandLength;

/// The length of the offside part of the clock's minute hand. Default value is 20.
@property (nonatomic) IBInspectable CGFloat minuteHandOffsideLength;


//----- SECONDS HAND CUSTOMIZATION -----//

/// The color of the clock's second hand. Default value is whiteColor.
@property (strong, nonatomic) IBInspectable UIColor *secondHandColor;

/// The alpha of the clock's second hand. Default value is 1.0.
@property (nonatomic) IBInspectable CGFloat secondHandAlpha;

/// The width of the clock's second hand. Default value is 1.0.
@property (nonatomic) IBInspectable CGFloat secondHandWidth;

/// The length of the clock's second hand. Default value is 60.
@property (nonatomic) IBInspectable CGFloat secondHandLength;

/// The length of the offside part of the clock's second hand. Default value is 20.
@property (nonatomic) IBInspectable CGFloat secondHandOffsideLength;


//----- HUB CUSTOMIZATION -----//

/// The color of the hub. Default value is whiteColor.
@property (strong, nonatomic) IBInspectable UIColor *hubColor;

/// The alpha of the clock's hub. Default value is 1.0.
@property (nonatomic) IBInspectable CGFloat hubAlpha;

/// The width of the clock's hub. Default value is 3.0.
@property (nonatomic) IBInspectable CGFloat hubRadius;

//------------------------------------------------------------------------------------//
//----- METHODS ----------------------------------------------------------------------//
//------------------------------------------------------------------------------------//

/// Reload the clock, all delegate methods are called again and the graph is reloaded/redrawn. Similar to calling reloadData on a UITableView.
- (void)reloadClock;

/** Update the time on the clock.
 @param animated If the change of position of the hands should be animated or not. */
- (void)updateTimeAnimated:(BOOL)animated;

/** When called, this method will set the clock to the current time on the phone.
 @param animated If the change of position of the hands should be animated or not. */
- (void)setClockToCurrentTimeAnimated:(BOOL)animated;

/// Start the real time feature. The clock will be updated in real time (the second hand will move every second, the minute one every minute and the hour one every hour).
- (void)startRealTime;

/// Stops the real time feature. The clock will not move anymore.
- (void)stopRealTime;

@end


@protocol BMAnalogClockDelegate <NSObject>

@optional


//----- TIME -----//

/** The time that is currently displayed on the clock. Gets called everytime the time on the clock changes.
 @param clock The clock object which is currently displaying the time.
 @param hours The hours currently displayed on the clock by the hour hand.
 @param minutes The minutes currently displayed on the clock by the minute hand.
 @param seconds The seconds currently displayed on the clock by the second hand. */
- (void)currentTimeOnClock:(BMAnalogClockView *)clock Hours:(NSString *)hours Minutes:(NSString *)minutes Seconds:(NSString *)seconds;


//----- DATA SOURCE -----//

/** The date format used to set up the time on the clock.
 @param clock The clock object which is in need of the date format.
 @return The date format string. */
- (NSString *)dateFormatterForClock:(BMAnalogClockView *)clock;

/** The date (with time) used to set up the hands of the clock.
 @param clock The clock object.
 @return The date used to set up the clock. Should conform to the date formatter provided in the methode dateFormatterForClock: */
- (NSString *)timeForClock:(BMAnalogClockView *)clock;


//----- GRADUATION CUSTOMIZATION -----//

/** The color of the graduation line at a given index. This is called for each graduation on the clock.
 @param clock The clock object requesting the graduation color.
 @param index The index from 0 to 59 of a given graduation. The first value for the index is 0.
 @return The color of the graduation at the specific index. */
- (UIColor *)analogClock:(BMAnalogClockView *)clock graduationColorForIndex:(NSInteger)index;

/** The alpha of the graduation line at a given index. This is called for each graduation on the clock.
 @param clock The clock object requesting the graduation alpha.
 @param index The index from 0 to 59 of a given graduation. The first value for the index is 0.
 @return The alpha value of the graduation at the specific index. */
- (CGFloat)analogClock:(BMAnalogClockView *)clock graduationAlphaForIndex:(NSInteger)index;

/** The width of the graduation line at a given index. This is called for each graduation on the clock.
 @param clock The clock object requesting the graduation width.
 @param index The index from 0 to 59 of a given graduation. The first value for the index is 0.
 @return The width value of the graduation at the specific index. */
- (CGFloat)analogClock:(BMAnalogClockView *)clock graduationWidthForIndex:(NSInteger)index;

/** The length of the graduation line at a given index. This is called for each graduation on the clock.
 @param clock The clock object requesting the graduation length.
 @param index The index from 0 to 59 of a given graduation. The first value for the index is 0.
 @return The length value of the graduation at the specific index. */
- (CGFloat)analogClock:(BMAnalogClockView *)clock graduationLengthForIndex:(NSInteger)index;

/** The offset of the graduation line from the border of the clock at a given index. This is called for each graduation on the clock.
 @param clock The clock object requesting the graduation offset.
 @param index The index from 0 to 59 of a given graduation. The first value for the index is 0.
 @return The offset value from the border of the clock of the graduation at the specific index. */
- (CGFloat)analogClock:(BMAnalogClockView *)clock graduationOffsetForIndex:(NSInteger)index;


//----- CLOCK EVENTS -----//

/** Sent to the delegate each time the clock is loaded or reloaded.
 @param clock The clock object that is about to be loaded or reloaded. */
- (void)clockDidBeginLoading:(BMAnalogClockView *)clock;

/** Sent to the delegate each time the clock finishes loading or reloading. Note that the animation is not finished at this point in time.
 @param clock The clock object that finished loading or reloading. */
- (void)clockDidFinishLoading:(BMAnalogClockView *)clock;

@end
