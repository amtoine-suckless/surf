# Patches for my fork of suckless dmenu.

## List of urls.

The below urls are marked with a tick when properly installed.  
The patches marked with `~` are installed in the sense that the code should be present, but do not work indeed.  
Patches have been patched with `patch -p1 < ./path/to/patch`.

|   | patch url                      | patch diff                                  |
|---|--------------------------------|---------------------------------------------|
|   | [aria2]                        |                                             |
|   | [autoopen]                     |                                             |
| x | [bookmarking]                  | [surf-bookmarks-20170722-723ff26.diff]      |
| x | [cachedir]                     | [surf-cachedir-20200831-2188894.diff]       |
|   | [chromebar]                    | [surf-0.1-chromebar.diff]                   |
|   | [chromekeys]                   | [surf-0.6-chromekeys.diff]                  |
|   | [clipboard-instead-of-primary] |                                             |
| x | [dlconsole]                    | [surf-dlconsole-20190919-d068a38.diff]      |
|   | [download]                     |                                             |
|   | [externalpipe]                 | [surf-2.0-externalpipe.diff]                |
|   | [externalpipe-signal]          |                                             |
| x | [history]                      | [surf-2.1-history.diff]                     |
| x | [homepage]                     | [surf-2.0-homepage.diff]                    |
|   | [instapaper]                   |                                             |
|   | [keycodes]                     |                                             |
|   | [middle-click-plumb]           |                                             |
| x | [modal]                        | [surf-modal-20190209-d068a38.diff]          |
| x | [multijs]                      | [surf-multijs-20190325-d068a38.diff]        |
|   | [navigation-history]           | [surf-0.6-navhist.diff]                     |
|   | [notifications]                | [surf-notifications-20201223-7dcce9e1.diff] |
|   | [omnibar]                      | [surf-0.7-omnibar.diff]                     |
| x | [playexternal]                 | [surf-playexternal-20190724-b814567.diff]   |
|   | [popup-on-gesture]             |                                             |
|   | [proxyconfig]                  |                                             |
| x | [quit-hotkey]                  | [surf-quit_hotkey-20210830-11dca18.diff]    |
| x | [scroll-faster]                | [surf-scrollmultiply-2.0.diff]              |
| x | [searchengines]                | [surf-0.7-webkit2-searchengines.diff]       |
|   | [short-title]                  | [surf-short-title-20210206-7dcce9e.diff]    |
|   | [smoothscrolling-via-GTK3]     | [surf-0.7-smoothscrolling.diff]             |
| x | [spacesearch]                  | [surf-spacesearch-20170408-b814567.diff]    |
|   | [startgo]                      |                                             |
|   | [unicode-in-dmenu]             | [surf-0.6-dmenu-unicode.diff]               |
| x | [url-filtering]                | [surf-tip-url-filtering.diff]               |
|   | [useragent]                    | [surf-websearch-20190510-d068a38.diff]      |
|   | [web-search]                   |                                             |
|   | [xdg]                          | [surf-xdg-2.0.diff]                         |
|   | [zoommtg-handler]              | [surf-zoommtghandler-2.1.diff]              |

<!-- all the patches at https://surf.suckless.org/patches/ -->
[aria2]:                        https://surf.suckless.org/patches/aria2
[autoopen]:                     https://surf.suckless.org/patches/autoopen
[bookmarking]:                  https://surf.suckless.org/patches/bookmarking
[cachedir]:                     https://surf.suckless.org/patches/cachedir
[chromebar]:                    https://surf.suckless.org/patches/chromebar
[chromekeys]:                   https://surf.suckless.org/patches/chromekeys
[clipboard-instead-of-primary]: https://surf.suckless.org/patches/clipboard-instead-of-primary
[dlconsole]:                    https://surf.suckless.org/patches/dlconsole
[download]:                     https://surf.suckless.org/patches/download
[externalpipe]:                 https://surf.suckless.org/patches/externalpipe
[externalpipe-signal]:          https://surf.suckless.org/patches/externalpipe-signal
[history]:                      https://surf.suckless.org/patches/history
[homepage]:                     https://surf.suckless.org/patches/homepage
[instapaper]:                   https://surf.suckless.org/patches/instapaper
[keycodes]:                     https://surf.suckless.org/patches/keycodes
[middle-click-plumb]:           https://surf.suckless.org/patches/middle-click-plumb
[modal]:                        https://surf.suckless.org/patches/modal
[multijs]:                      https://surf.suckless.org/patches/multijs
[navigation-history]:           https://surf.suckless.org/patches/navigation-history
[notifications]:                https://surf.suckless.org/patches/notifications
[omnibar]:                      https://surf.suckless.org/patches/omnibar
[playexternal]:                 https://surf.suckless.org/patches/playexternal
[popup-on-gesture]:             https://surf.suckless.org/patches/popup-on-gesture
[proxyconfig]:                  https://surf.suckless.org/patches/proxyconfig
[quit-hotkey]:                  https://surf.suckless.org/patches/quit-hotkey
[scroll-faster]:                https://surf.suckless.org/patches/scroll-faster
[searchengines]:                https://surf.suckless.org/patches/searchengines
[short-title]:                  https://surf.suckless.org/patches/short-title
[smoothscrolling-via-GTK3]:     https://surf.suckless.org/patches/smoothscrolling-via-GTK3
[spacesearch]:                  https://surf.suckless.org/patches/spacesearch
[startgo]:                      https://surf.suckless.org/patches/startgo
[unicode-in-dmenu]:             https://surf.suckless.org/patches/unicode-in-dmenu
[url-filtering]:                https://surf.suckless.org/patches/url-filtering
[useragent]:                    https://surf.suckless.org/patches/useragent
[web-search]:                   https://surf.suckless.org/patches/web-search
[xdg]:                          https://surf.suckless.org/patches/xdg
[zoommtg-handler]:              https://surf.suckless.org/patches/zoommtg-handler

<!-- all the downloaded diffs -->
[surf-bookmarks-20170722-723ff26.diff]:      surf-bookmarks-20170722-723ff26.diff
[surf-cachedir-20200831-2188894.diff]:       surf-cachedir-20200831-2188894.diff
[surf-0.1-chromebar.diff]:                   surf-0.1-chromebar.diff
[surf-0.6-chromekeys.diff]:                  surf-0.6-chromekeys.diff
[surf-dlconsole-20190919-d068a38.diff]:      surf-dlconsole-20190919-d068a38.diff
[surf-2.0-externalpipe.diff]:                surf-2.0-externalpipe.diff
[surf-2.1-history.diff]:                     surf-2.1-history.diff
[surf-2.0-homepage.diff]:                    surf-2.0-homepage.diff
[surf-modal-20190209-d068a38.diff]:          surf-modal-20190209-d068a38.diff
[surf-multijs-20190325-d068a38.diff]:        surf-multijs-20190325-d068a38.diff
[surf-0.6-navhist.diff]:                     surf-0.6-navhist.diff
[surf-notifications-20201223-7dcce9e1.diff]: surf-notifications-20201223-7dcce9e1.diff
[surf-0.7-omnibar.diff]:                     surf-0.7-omnibar.diff
[surf-playexternal-20190724-b814567.diff]:   surf-playexternal-20190724-b814567.diff
[surf-quit_hotkey-20210830-11dca18.diff]:    surf-quit_hotkey-20210830-11dca18.diff
[surf-scrollmultiply-2.0.diff]:              surf-scrollmultiply-2.0.diff
[surf-0.7-webkit2-searchengines.diff]:       surf-0.7-webkit2-searchengines.diff
[surf-short-title-20210206-7dcce9e.diff]:    surf-short-title-20210206-7dcce9e.diff
[surf-0.7-smoothscrolling.diff]:             surf-0.7-smoothscrolling.diff
[surf-spacesearch-20170408-b814567.diff]:    surf-spacesearch-20170408-b814567.diff
[surf-0.6-dmenu-unicode.diff]:               surf-0.6-dmenu-unicode.diff
[surf-tip-url-filtering.diff]:               surf-tip-url-filtering.diff
[surf-websearch-20190510-d068a38.diff]:      surf-websearch-20190510-d068a38.diff
[surf-xdg-2.0.diff]:                         surf-xdg-2.0.diff
[surf-zoommtghandler-2.1.diff]:              surf-zoommtghandler-2.1.diff
