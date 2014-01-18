/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import <XXUnknownSuperclass.h> // Unknown library

@class UIImage, NSString, MusicAlbumSquareCoverView, UIButton, UILabel;

__attribute__((visibility("hidden")))
@interface MusicAlbumSectionView : XXUnknownSuperclass {
	UILabel* _albumLabel;
	UILabel* _artistLabel;
	UILabel* _copyrightLabel;
	UIButton* _downloadAllButton;
	UIButton* _addAllEntitiesButton;
	MusicAlbumSquareCoverView* _imageView;
@private
	UILabel* _releaseDateLabel;
}
@property(copy, nonatomic) NSString* releaseDate;
@property(retain, nonatomic) UIButton* addAllEntitiesButton;	// @synthesize=_addAllEntitiesButton
@property(retain, nonatomic) UIButton* downloadAllButton;	// @synthesize=_downloadAllButton
@property(copy, nonatomic) NSString* copyright;
@property(copy, nonatomic) NSString* artist;
@property(copy, nonatomic) NSString* album;
@property(retain, nonatomic) UIImage* image;
// declared property getter: -(id)addAllEntitiesButton;
// declared property getter: -(id)downloadAllButton;
// declared property setter: -(void)setReleaseDate:(id)date;
// declared property getter: -(id)releaseDate;
// declared property setter: -(void)setImage:(id)image;
// declared property getter: -(id)image;
// declared property setter: -(void)setAddAllEntitiesButton:(id)button;
// declared property setter: -(void)setDownloadAllButton:(id)button;
// declared property setter: -(void)setCopyright:(id)copyright;
// declared property getter: -(id)copyright;
// declared property setter: -(void)setArtist:(id)artist;
// declared property getter: -(id)artist;
// declared property setter: -(void)setAlbum:(id)album;
// declared property getter: -(id)album;
-(void)layoutSubviews;
-(void)dealloc;
-(id)initWithImage:(id)image;
@end

