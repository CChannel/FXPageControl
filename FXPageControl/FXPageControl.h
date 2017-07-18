//
//  FXPageControl.h
//
//  Version 1.5
//
//  Created by Nick Lockwood on 07/01/2010.
//  Copyright 2010 Charcoal Design
//
//  Distributed under the permissive zlib License
//  Get the latest version of FXPageControl from here:
//
//  https://github.com/nicklockwood/FXPageControl
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-property-synthesis"
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN


extern const CGPathRef FXPageControlDotShapeCircle;
extern const CGPathRef FXPageControlDotShapeSquare;
extern const CGPathRef FXPageControlDotShapeTriangle;


@protocol FXPageControlDelegate;


@interface FXPageControl : UIControl

- (void)setUp;
- (CGSize)sizeForNumberOfPages:(NSInteger)pageCount;
- (void)updateCurrentPageDisplay;

@property (nonatomic, weak) IBOutlet id <FXPageControlDelegate> delegate;

@property (nonatomic, assign) NSInteger currentPage;
@property (nonatomic, assign) NSInteger numberOfPages;
@property (nonatomic, assign) BOOL defersCurrentPageDisplay;
@property (nonatomic, assign) BOOL hidesForSinglePage;
@property (nonatomic, assign, getter = isWrapEnabled) BOOL wrapEnabled;
@property (nonatomic, assign, getter = isVertical) BOOL vertical;

@property (nonatomic, assign) CGPathRef dotShape;
@property (nonatomic, assign) CGFloat dotSize;
@property (nonatomic, assign) CGFloat dotShadowBlur;
@property (nonatomic, assign) CGSize dotShadowOffset;
@property (nonatomic, assign) CGFloat dotBorderWidth;
@property (nonatomic, strong, nullable) UIImage *dotImage;
@property (nonatomic, strong, nullable) UIColor *dotColor;
@property (nonatomic, strong, nullable) UIColor *dotShadowColor;
@property (nonatomic, strong, nullable) UIColor *dotBorderColor;

@property (nonatomic, assign) CGPathRef selectedDotShape;
@property (nonatomic, assign) CGFloat selectedDotSize;
@property (nonatomic, assign) CGFloat selectedDotShadowBlur;
@property (nonatomic, assign) CGSize selectedDotShadowOffset;
@property (nonatomic, assign) CGFloat selectedDotBorderWidth;
@property (nonatomic, strong, nullable) UIImage *selectedDotImage;
@property (nonatomic, strong, nullable) UIColor *selectedDotColor;
@property (nonatomic, strong, nullable) UIColor *selectedDotShadowColor;
@property (nonatomic, strong, nullable) UIColor *selectedDotBorderColor;

@property (nonatomic, assign) CGFloat dotSpacing;

@end


@protocol FXPageControlDelegate <NSObject>
@optional

- (UIImage *)pageControl:(FXPageControl *)pageControl imageForDotAtIndex:(NSInteger)index;
- (CGPathRef)pageControl:(FXPageControl *)pageControl shapeForDotAtIndex:(NSInteger)index;
- (UIColor *)pageControl:(FXPageControl *)pageControl colorForDotAtIndex:(NSInteger)index;

- (UIImage *)pageControl:(FXPageControl *)pageControl selectedImageForDotAtIndex:(NSInteger)index;
- (CGPathRef)pageControl:(FXPageControl *)pageControl selectedShapeForDotAtIndex:(NSInteger)index;
- (UIColor *)pageControl:(FXPageControl *)pageControl selectedColorForDotAtIndex:(NSInteger)index;

@end


NS_ASSUME_NONNULL_END


#pragma clang diagnostic pop
