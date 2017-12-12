//
//  LocalRecordViewController.h
//  lechangeDemo
//
//  Created by mac318340418 on 16/7/11.
//  Copyright © 2016年 dh-Test. All rights reserved.
//

#import "DeviceViewController.h"
#import "MyViewController.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, RecordType) {
    DeviceRecord = 0,
    CloudRecord = 1
};

@interface RecordViewController : MyViewController {
    LCOpenSDK_Api* m_hc;
    NSString* m_strAccessToken;
    
    UIActivityIndicatorView* m_progressInd;
    UILabel* m_toastLab;
    NSString* m_accessToken;
    NSString* m_strDevSelected;
    NSInteger m_devChnSelected;
    RecordType m_recordType;
    NSString* m_strRecSelected;
    NSString* m_beginTimeSelected;
    NSString* m_endTimeSelected;
    UIImage* m_imgPicSelected;
}

@property (weak, nonatomic) IBOutlet UIView* m_viewDateBar;
@property (weak, nonatomic) IBOutlet UIDatePicker* m_datePicker;
@property (weak, nonatomic) IBOutlet UIImageView* m_ImgRecordNull;
@property (weak, nonatomic) IBOutlet UITableView *m_listView;

- (void)setInfo:(NSString*)token Dev:(NSString*)deviceId Chn:(NSInteger)chn Type:(RecordType)type;
- (void)downloadThread;
- (void)destroyThread;
- (void)onDownloadReceiveData:(NSInteger)index datalen:(NSInteger)datalen;
- (void)onDownloadState:(NSInteger)index code:(NSString*)code type:(NSInteger)type;
- (void)onDownloadEnd:(NSInteger)index;



- (IBAction)onBack:(id)sender;
- (IBAction)onSearch:(id)sender;
- (IBAction)onCancel:(id)sender;
- (IBAction)onQuery:(id)sender;
@end
