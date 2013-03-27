//
//  GTTimeAdditionsSpec.m
//  ObjectiveGitFramework
//
//  Created by Danny Greg on 27/03/2013.
//  Copyright (c) 2013 GitHub, Inc. All rights reserved.
//

#import "NSDate+GTTimeAdditions.h"

SpecBegin(GTTimeAdditions)

describe(@"Convertion between git_time and NSDate", ^{
	it(@"should be able to create an NSDate when given a git_time", ^{
		git_time_t seconds = 1265374800;
		int offset = -120; //2 hours behind GMT
		git_time time = (git_time){ .time = seconds, .offset = offset };
		NSDate *date = [NSDate gt_dateFromGitTime:time];
		expect(date).toNot.beNil();
		
		NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
		NSDateComponents *components = [gregorianCalendar components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit | NSHourCalendarUnit fromDate:date];
		expect(components).toNot.beNil();
		
		expect(components.day).to.equal(5);
		expect(components.month).to.equal(2);
		expect(components.year).to.equal(2010);
		expect(components.hour).to.equal(11);
	});
	
	it(@"should return a correct offset for an NSDate", ^{
		NSDate *date = [NSDate dateWithString:@"2012-11-02 15:38:46 +0200"];
		expect(date).toNot.beNil();
		expect(date.gt_gitTimeOffset).to.equal(120);
	});
	
	it(@"should return a correct git_time for an NSDate", ^{
		NSDate *date = [NSDate dateWithString:@"2010-05-12 18:29:13 +0000"];
		expect(date).toNot.beNil();
		expect(date.gt_gitTime.time).to.equal(1273688953);
	});
});

SpecEnd
