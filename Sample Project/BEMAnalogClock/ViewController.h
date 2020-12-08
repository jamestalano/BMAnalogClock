//
//  ViewController.h
//  BMAnalogClockView
//
//  Created by James Talano on 2/23/14.
//  Copyright (c) 2014 James Talano. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BEMAnalogClockView.h"

@interface ViewController : UIViewController <BMAnalogClockDelegate, UIGestureRecognizerDelegate>

@property (weak, nonatomic) IBOutlet BMAnalogClockView *myClock1; // The big, main clock.
@property (weak, nonatomic) IBOutlet BMAnalogClockView *myClock2; // The smaller clock.
@property (strong, nonatomic) IBOutlet UILabel *myLabel;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *refreshButton;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *currentTimeButton;
@property (weak, nonatomic) IBOutlet UIView *panView;

- (IBAction)pushRefreshButton:(id)sender;
- (IBAction)pushCurrentTimeButton:(id)sender;

@end
