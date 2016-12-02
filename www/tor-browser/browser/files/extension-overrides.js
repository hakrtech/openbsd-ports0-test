# Overrides for Extension Preferences
# Tor Browser Bundle
# Do not edit this file.

# Torbutton Preferences:
pref("extensions.torbutton.fresh_install", false);
pref("extensions.torbutton.tor_enabled", true);
pref("extensions.torbutton.proxies_applied", true);
pref("extensions.torbutton.settings_applied", true);
pref("extensions.torbutton.socks_host", "127.0.0.1");
pref("extensions.torbutton.socks_port", 9150);
pref("extensions.torbutton.tz_string", "UTC+00:00");

# HTTPS Everywhere Preferences:
pref("extensions.https_everywhere._observatory.popup_shown", true);
pref("extensions.https_everywhere.toolbar_hint_shown", true);

# NoScript Preferences:
pref("capability.policy.maonoscript.javascript.enabled", "allAccess");
pref("capability.policy.maonoscript.sites", "about: about:tbupdate chrome: resource: blob: mediasource: moz-safe-about:");
pref("noscript.default", "about: about:tbupdate chrome: resource: blob: mediasource: moz-safe-about:");
pref("noscript.mandatory", "about: about:tbupdate chrome: resource: blob: mediasource: moz-safe-about:");
pref("noscript.ABE.enabled", false);
pref("noscript.ABE.notify", false);
pref("noscript.ABE.wanIpAsLocal", false);
pref("noscript.confirmUnblock", false);
pref("noscript.contentBlocker", true);
pref("noscript.firstRunRedirection", false);
pref("noscript.global", true);
pref("noscript.gtemp", "");
pref("noscript.opacizeObject", 3);
pref("noscript.forbidWebGL", true);
pref("noscript.forbidFonts", false);
pref("noscript.options.tabSelectedIndexes", "5,0,0");
pref("noscript.policynames", "");
pref("noscript.secureCookies", true);
pref("noscript.showAllowPage", false);
pref("noscript.showBaseDomain", false);
pref("noscript.showDistrust", false);
pref("noscript.showRecentlyBlocked", false);
pref("noscript.showTemp", false);
pref("noscript.showTempToPerm", false);
pref("noscript.showUntrusted", false);
pref("noscript.STS.enabled", false);
pref("noscript.subscription.lastCheck", -142148139);
pref("noscript.temp", "");
pref("noscript.untrusted", "");
pref("noscript.forbidMedia", false);
pref("noscript.allowWhitelistUpdates", false);
// Now handled by plugins.click_to_play
pref("noscript.forbidFlash", false);
pref("noscript.forbidSilverlight", false);
pref("noscript.forbidJava", false);
pref("noscript.forbidPlugins", false);
// Usability tweaks
pref("noscript.showPermanent", false);
pref("noscript.showTempAllowPage", true);
pref("noscript.showRevokeTemp", true);
pref("noscript.notify", false);
pref("noscript.autoReload", true);
pref("noscript.autoReload.allTabs", false);
pref("noscript.cascadePermissions", true);
pref("noscript.restrictSubdocScripting", true);
pref("noscript.showVolatilePrivatePermissionsToggle", false);
pref("noscript.volatilePrivatePermissions", true);
pref("noscript.clearClick", 0);
# Tor Launcher preferences (default bridges):
pref("extensions.torlauncher.default_bridge_recommended_type", "obfs4");

// Default bridges.
pref("extensions.torlauncher.default_bridge.obfs3.1", "obfs3 83.212.101.3:80 A09D536DD1752D542E1FBB3C9CE4449D51298239");
pref("extensions.torlauncher.default_bridge.obfs3.2", "obfs3 169.229.59.74:31493 AF9F66B7B04F8FF6F32D455F05135250A16543C9");
pref("extensions.torlauncher.default_bridge.obfs3.3", "obfs3 169.229.59.75:46328 AF9F66B7B04F8FF6F32D455F05135250A16543C9");
pref("extensions.torlauncher.default_bridge.obfs3.4", "obfs3 109.105.109.163:38980 1E05F577A0EC0213F971D81BF4D86A9E4E8229ED");
pref("extensions.torlauncher.default_bridge.obfs3.5", "obfs3 109.105.109.163:47779 4C331FA9B3D1D6D8FB0D8FBBF0C259C360D97E6A");

pref("extensions.torlauncher.default_bridge.fte.1", "fte 131.252.210.150:8080 0E858AC201BF0F3FA3C462F64844CBFFC7297A42");
pref("extensions.torlauncher.default_bridge.fte.2", "fte 128.105.214.161:8080 1E326AAFB3FCB515015250D8FCCC8E37F91A153B");
pref("extensions.torlauncher.default_bridge.fte.3", "fte 128.105.214.162:8080 FC562097E1951DCC41B7D7F324D88157119BB56D");
pref("extensions.torlauncher.default_bridge.fte.4", "fte 128.105.214.163:8080 A17A40775FBD2CA1184BF80BFC330A77ECF9D0E9");

pref("extensions.torlauncher.default_bridge.scramblesuit.1", "scramblesuit 83.212.101.3:443 A09D536DD1752D542E1FBB3C9CE4449D51298239 password=XTCXLG2JAMJKZW2POLBAOWOQETQSMASH");

pref("extensions.torlauncher.default_bridge.obfs4.1", "obfs4 154.35.22.10:9332 8FB9F4319E89E5C6223052AA525A192AFBC85D55 cert=GGGS1TX4R81m3r0HBl79wKy1OtPPNR2CZUIrHjkRg65Vc2VR8fOyo64f9kmT1UAFG7j0HQ iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.2", "obfs4 198.245.60.50:443 752CF7825B3B9EA6A98C83AC41F7099D67007EA5 cert=xpmQtKUqQ/6v5X7ijgYE/f03+l2/EuQ1dexjyUhh16wQlu/cpXUGalmhDIlhuiQPNEKmKw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.3", "obfs4 192.99.11.54:443 7B126FAB960E5AC6A629C729434FF84FB5074EC2 cert=VW5f8+IBUWpPFxF+rsiVy2wXkyTQG7vEd+rHeN2jV5LIDNu8wMNEOqZXPwHdwMVEBdqXEw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.4", "obfs4 109.105.109.165:10527 8DFCD8FB3285E855F5A55EDDA35696C743ABFC4E cert=Bvg/itxeL4TWKLP6N1MaQzSOC6tcRIBv6q57DYAZc3b2AzuM+/TfB7mqTFEfXILCjEwzVA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.5", "obfs4 83.212.101.3:50001 A09D536DD1752D542E1FBB3C9CE4449D51298239 cert=lPRQ/MXdD1t5SRZ9MquYQNT9m5DV757jtdXdlePmRCudUU9CFUOX1Tm7/meFSyPOsud7Cw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.6", "obfs4 109.105.109.147:13764 BBB28DF0F201E706BE564EFE690FE9577DD8386D cert=KfMQN/tNMFdda61hMgpiMI7pbwU1T+wxjTulYnfw+4sgvG0zSH7N7fwT10BI8MUdAD7iJA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.7", "obfs4 154.35.22.11:7920 A832D176ECD5C7C6B58825AE22FC4C90FA249637 cert=YPbQqXPiqTUBfjGFLpm9JYEFTBvnzEJDKJxXG5Sxzrr/v2qrhGU4Jls9lHjLAhqpXaEfZw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.8", "obfs4 154.35.22.12:80 00DC6C4FA49A65BD1472993CF6730D54F11E0DBB cert=N86E9hKXXXVz6G7w2z8wFfhIDztDAzZ/3poxVePHEYjbKDWzjkRDccFMAnhK75fc65pYSg iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.9", "obfs4 154.35.22.13:443 FE7840FE1E21FE0A0639ED176EDA00A3ECA1E34D cert=fKnzxr+m+jWXXQGCaXe4f2gGoPXMzbL+bTBbXMYXuK0tMotd+nXyS33y2mONZWU29l81CA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.10", "obfs4 154.35.22.10:80 8FB9F4319E89E5C6223052AA525A192AFBC85D55 cert=GGGS1TX4R81m3r0HBl79wKy1OtPPNR2CZUIrHjkRg65Vc2VR8fOyo64f9kmT1UAFG7j0HQ iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.11", "obfs4 154.35.22.10:443 8FB9F4319E89E5C6223052AA525A192AFBC85D55 cert=GGGS1TX4R81m3r0HBl79wKy1OtPPNR2CZUIrHjkRg65Vc2VR8fOyo64f9kmT1UAFG7j0HQ iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.12", "obfs4 154.35.22.11:443 A832D176ECD5C7C6B58825AE22FC4C90FA249637 cert=YPbQqXPiqTUBfjGFLpm9JYEFTBvnzEJDKJxXG5Sxzrr/v2qrhGU4Jls9lHjLAhqpXaEfZw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.13", "obfs4 154.35.22.11:80 A832D176ECD5C7C6B58825AE22FC4C90FA249637 cert=YPbQqXPiqTUBfjGFLpm9JYEFTBvnzEJDKJxXG5Sxzrr/v2qrhGU4Jls9lHjLAhqpXaEfZw iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.14", "obfs4 154.35.22.9:7013 C73ADBAC8ADFDBF0FC0F3F4E8091C0107D093716 cert=gEGKc5WN/bSjFa6UkG9hOcft1tuK+cV8hbZ0H6cqXiMPLqSbCh2Q3PHe5OOr6oMVORhoJA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.15", "obfs4 154.35.22.9:80 C73ADBAC8ADFDBF0FC0F3F4E8091C0107D093716 cert=gEGKc5WN/bSjFa6UkG9hOcft1tuK+cV8hbZ0H6cqXiMPLqSbCh2Q3PHe5OOr6oMVORhoJA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.16", "obfs4 154.35.22.9:443 C73ADBAC8ADFDBF0FC0F3F4E8091C0107D093716 cert=gEGKc5WN/bSjFa6UkG9hOcft1tuK+cV8hbZ0H6cqXiMPLqSbCh2Q3PHe5OOr6oMVORhoJA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.17", "obfs4 154.35.22.12:4148 00DC6C4FA49A65BD1472993CF6730D54F11E0DBB cert=N86E9hKXXXVz6G7w2z8wFfhIDztDAzZ/3poxVePHEYjbKDWzjkRDccFMAnhK75fc65pYSg iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.18", "obfs4 154.35.22.13:6041 FE7840FE1E21FE0A0639ED176EDA00A3ECA1E34D cert=fKnzxr+m+jWXXQGCaXe4f2gGoPXMzbL+bTBbXMYXuK0tMotd+nXyS33y2mONZWU29l81CA iat-mode=0");
pref("extensions.torlauncher.default_bridge.obfs4.19", "obfs4 192.95.36.142:443 CDF2E852BF539B82BD10E27E9115A31734E378C2 cert=qUVQ0srL1JI/vO6V6m/24anYXiJD3QP2HgzUKQtQ7GRqqUvs7P+tG43RtAqdhLOALP7DJQ iat-mode=0");
// Not used yet
// pref("extensions.torlauncher.default_bridge.obfs4.20", "obfs4 85.17.30.79:443 FC259A04A328A07FED1413E9FC6526530D9FD87A cert=RutxZlu8BtyP+y0NX7bAVD41+J/qXNhHUrKjFkRSdiBAhIHIQLhKQ2HxESAKZprn/lR3KA iat-mode=0");

pref("extensions.torlauncher.default_bridge.meek-amazon.1", "meek 0.0.2.0:2 B9E7141C594AF25699E0079C1F0146F409495296 url=https://d2zfqthxsdq309.cloudfront.net/ front=a0.awsstatic.com");
pref("extensions.torlauncher.default_bridge.meek-azure.1", "meek 0.0.2.0:3 A2C13B7DFCAB1CBF3A884B6EB99A98067AB6EF44 url=https://az786092.vo.msecnd.net/ front=ajax.aspnetcdn.com");
pref("extensions.torlauncher.prompt_for_locale", false);
pref("intl.locale.matchOS", false);
