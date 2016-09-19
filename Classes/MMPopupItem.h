//
//  MMActionItem.h
//  MMPopupView
//
//  Created by Ralph Li on 9/6/15.
//  Copyright © 2015 LJC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^MMPopupItemHandler)(NSInteger index);

@interface MMPopupItem : NSObject

@property (nonatomic, assign) BOOL     highlight;
@property (nonatomic, assign) BOOL     disabled;

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *imageHighlight;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIColor  *color;

@property (nonatomic, copy)   MMPopupItemHandler handler;

@end

typedef NS_ENUM(NSUInteger, MMItemType) {
    MMItemTypeNormal,
    MMItemTypeHighlight,
    MMItemTypeDisabled
};

NS_INLINE MMPopupItem* MMItemMake(NSString* title, MMItemType type, MMPopupItemHandler handler)
{
    MMPopupItem *item = [MMPopupItem new];
    
    item.title = title;
    item.handler = handler;
    
    switch (type)
    {
        case MMItemTypeNormal:
        {
            break;
        }
        case MMItemTypeHighlight:
        {
            item.highlight = YES;
            break;
        }
        case MMItemTypeDisabled:
        {
            item.disabled = YES;
            break;
        }
        default:
            break;
    }
    
    return item;
}

NS_INLINE MMPopupItem* MMItemMakeImage(NSString* imageName, MMItemType type, MMPopupItemHandler handler)
{
    MMPopupItem *item = [MMPopupItem new];
    
    item.image = [UIImage imageNamed:imageName];
    item.imageHighlight = [UIImage imageNamed:[NSString stringWithFormat:@"%@_highlight", imageName]];
    item.handler = handler;
    
    switch (type)
    {
        case MMItemTypeNormal:
        {
            break;
        }
        case MMItemTypeHighlight:
        {
            item.highlight = YES;
            break;
        }
        case MMItemTypeDisabled:
        {
            item.disabled = YES;
            break;
        }
        default:
            break;
    }
    
    return item;
}
