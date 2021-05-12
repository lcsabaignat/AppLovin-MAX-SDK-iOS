//
//  MAInterstitial.h
//  AppLovinSDK
//
//  Created by Thomas So on 8/9/18.
//  Copyright © 2020 AppLovin Corporation. All rights reserved.
//

#import "ALSdk.h"
#import "MAAdDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This class represents a full-screen interstitial ad.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/interstitials">MAX Integration Guide ⇒ iOs ⇒ Interstitials</a>
 */
@interface MAInterstitialAd : NSObject

/**
 * Creates a new mediation interstitial.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier;

/**
 * Creates a new mediation interstitial.
 *
 * @param adUnitIdentifier Ad unit ID to load ads for.
 * @param sdk              SDK to use. You can obtain an instance of the SDK by calling {@link ALSdk::shared}.
 */
- (instancetype)initWithAdUnitIdentifier:(NSString *)adUnitIdentifier sdk:(ALSdk *)sdk;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * A delegate that will be notified about ad events.
 */
@property (nonatomic, weak, nullable) id<MAAdDelegate> delegate;

/**
 * Sets an extra key/value parameter for the ad.
 *
 * @param key   Parameter key.
 * @param value Parameter value.
 */
- (void)setExtraParameterForKey:(NSString *)key value:(nullable NSString *)value;

/**
 * Load the ad for the current interstitial. Set {@link delegate} to assign a delegate that should be notified about ad load state.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/interstitials#loading-an-interstitial-ad">MAX Integration Guide ⇒ iOs ⇒ Interstitials ⇒ Loading an Interstitial Ad</a>
 */
- (void)loadAd;

/**
 * Show the loaded interstitial.
 * <ul>
 * <li>Use {@link delegate} to assign a delegate that should be notified about display events.</li>
 * <li>Use {@link ready} to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/interstitials#showing-an-interstitial-ad">MAX Integration Guide ⇒ iOs ⇒ Interstitials ⇒ Showing an Interstitial Ad</a>
 */
- (void)showAd;

/**
 * Show the loaded interstitial for a given placement to tie ad events to.
 * <ul>
 * <li>Use {@link delegate} to assign a delegate that should be notified about display events.</li>
 * <li>Use {@link ready} to check if an ad was successfully loaded.</li>
 * </ul>
 *
 * @param placement The placement to tie the showing ad's events to.
 *
 * @see <a href="https://dash.applovin.com/documentation/mediation/ios/getting-started/advanced-settings#ad-placements">MAX Integration Guide ⇒ iOS ⇒ Advanced Settings ⇒ Ad Placements</a>
 */
 // [PLP] what does it mean to "tie" an event to a placement? who ties?
- (void)showAdForPlacement:(nullable NSString *)placement;

/**
 * The ad unit identifier this `MAInterstitialAd` was initialized with and is loading ads for.
 */
@property (nonatomic, copy, readonly) NSString *adUnitIdentifier;

/**
 * Whether or not this ad is ready to be shown.
 */
@property (nonatomic, assign, readonly, getter=isReady) BOOL ready;

@end

NS_ASSUME_NONNULL_END
