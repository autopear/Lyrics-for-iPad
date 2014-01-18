/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

#import "MusicStandardGridConfiguration.h"


__attribute__((visibility("hidden")))
@interface MusicAlbumGridConfiguration : MusicStandardGridConfiguration {
}
+(void)configureView:(id)view forViewController:(id)viewController withEntity:(id)entity atIndexPath:(id)indexPath;
+(void)decodeArtworkForEntities:(id)entities waitUntilDone:(BOOL)done;
+(BOOL)shouldPrefetchArtwork;
+(id)newGridView;
+(id)_imageCache;
+(id)gridViewBackgroundImageName;
+(void)initialize;
@end

