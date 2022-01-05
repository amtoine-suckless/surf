/* #define HOMEPAGE "https://duckduckgo.com/" */
#define HOMEPAGE "~/.config/surf/html/homepage.html"

/* modifier 0 means no modifier */
static int surfuseragent    = 1;  /* Append Surf version to default WebKit user agent */
static char *fulluseragent  = ""; /* Or override the whole user agent string */
static char *styledir       = "~/.config/surf/styles/";
static char *certdir        = "~/.config/surf/certificates/";
static char *cachedir       = "~/.config/surf/cache/";
static char *cookiefile     = "~/.config/surf/cookies.txt";
static char *dldir          = "~/dl/";
static char *dlstatus       = "~/.config/surf/dlstatus/";
static char *historyfile    = "~/.config/surf/history.txt";
static char *scriptfiles[]  = {
  "~/.config/surf/scripts/link_hints.js"
};


/* Regular expressions to match URLs that should not be loaded */
char *filter_patterns[] = {
#include "filters_compiled"
};


/* Define this for verbose filtering */
// #define FILTER_VERBOSE

/* Webkit default features */
/* Highest priority value will be used.
 * Default parameters are priority 0
 * Per-uri parameters are priority 1
 * Command parameters are priority 2
 */
static Parameter defconfig[ParameterLast] = {
  /* parameter              Arg value       priority */
  [AccessMicrophone]    = { { .i = 0 },     },
  [AccessWebcam]        = { { .i = 0 },     },
  [Certificate]         = { { .i = 0 },     },
  [CaretBrowsing]       = { { .i = 0 },     },
  [CookiePolicies]      = { { .v = "@Aa" }, },
  [DefaultCharset]      = { { .v = "UTF-8" }, },
  [DiskCache]           = { { .i = 1 },     },
  [DNSPrefetch]         = { { .i = 0 },     },
  [Ephemeral]           = { { .i = 0 },     },
  [FileURLsCrossAccess] = { { .i = 0 },     },
  [FontSize]            = { { .i = 16 },    },
  [FrameFlattening]     = { { .i = 0 },     },
  [Geolocation]         = { { .i = 0 },     },
  [HideBackground]      = { { .i = 0 },     },
  [Inspector]           = { { .i = 1 },     },
  [Java]                = { { .i = 1 },     },
  [JavaScript]          = { { .i = 1 },     },
  [KioskMode]           = { { .i = 0 },     },
  [LoadImages]          = { { .i = 1 },     },
  [MediaManualPlay]     = { { .i = 1 },     },
  [PreferredLanguages]  = { { .v = (char *[]){ NULL } }, },
  [RunInFullscreen]     = { { .i = 0 },     },
  [ScrollBars]          = { { .i = 1 },     },
  [ShowIndicators]      = { { .i = 1 },     },
  [SiteQuirks]          = { { .i = 1 },     },
  [SmoothScrolling]     = { { .i = 0 },     },
  [SpellChecking]       = { { .i = 0 },     },
  [SpellLanguages]      = { { .v = ((char *[]){ "en_US", NULL }) }, },
  [StrictTLS]           = { { .i = 1 },     },
  [Style]               = { { .i = 1 },     },
  [WebGL]               = { { .i = 0 },     },
  [ZoomLevel]           = { { .f = 1.0 },   },
  [ClipboardNotPrimary] = { { .i = 1 },     },
};

static UriParameters uriparams[] = {
  { "(://|\\.)suckless\\.org(/|$)", {
    [JavaScript] = { { .i = 0 }, 1 },
  }, },
};

/* default window size: width, height */
static int winsize[] = { 800, 600 };

static WebKitFindOptions findopts = WEBKIT_FIND_OPTIONS_CASE_INSENSITIVE |
                                    WEBKIT_FIND_OPTIONS_WRAP_AROUND;


#define PROMPT_GO   "Go:"
#define PROMPT_FIND "Find:"

/* SETPROP(readprop, setprop, prompt)*/
#define SETPROP(r, s, p) { .v = (const char *[]){ "/bin/sh", "-c", \
  "~/.config/surf/scripts/dmenu.setprop.sh \"$0\" \"$1\" \"$2\" \"$3\" \"$4\"", \
"surf-setprop", winid, r, s, p, NULL }}

static char *linkselect_curwin [] = { "/bin/sh", "-c",
  "~/.config/surf/scripts/dmenu.linkselect.sh $0 'Link' | xargs -r xprop -id $0 -f _SURF_GO 8u -set _SURF_GO",
winid, NULL };
static char *linkselect_newwin [] = { "/bin/sh", "-c",
  "~/.config/surf/scripts/dmenu.linkselect.sh $0 'Link (new window)' | xargs -r surf",
winid, NULL };
static char *editscreen[] = { "/bin/sh", "-c",
  "~/.config/surf/scripts/edit.screen.sh",
NULL };
static char *editbookmarks[] = { "/bin/sh", "-c",
  "~/.config/surf/scripts/edit.bookmarks.sh",
NULL };
static char *openhelp[] = { "/bin/sh", "-c",
  "~/.config/surf/scripts/open.help.sh",
NULL };

/* SETURI(seturi)*/
#define SETURI(s) { .v = (const char *[]){ "/bin/sh", "-c", \
  "prop=\"`~/.config/surf/scripts/dmenu.uri.sh`\" &&" \
  "xprop -id $1 -f $2 8u -set $2 \"$prop\"", \
"surf-seturi", winid, s, NULL }}

#define DLSTATUS { .v = (const char *[]){ "kitty", "/bin/sh", "-c", \
"while true; do cat $1/* 2>/dev/null || echo \"no hay descargas\";" \
"A=; read A; " \
"if [ $A = \"clean\" ]; then rm $1/*; fi; clear; done", \
"surf-dlstatus", dlstatus, NULL }}

/* PLUMB(URI) */
/* This called when some URI which does not begin with "about:",
 * "http://" or "https://" should be opened.
 */
#define PLUMB(u) { .v = (const char *[]){ "/bin/sh", "-c", \
  "xdg-open \"$0\"", \
u, NULL }}

/* VIDEOPLAY(URI) */
#define VIDEOPLAY(u) { .v = (const char *[]){ "/bin/sh", "-c", \
  "~/.config/surf/scripts/dmenu.mpv.sh \"$0\"", \
u, NULL }}

/* BM_ADD(readprop) */
#define BM_ADD(r) { .v = (const char *[]){ "/bin/sh", "-c", \
  "~/.config/surf/scripts/add.bm.sh \"$0\" \"$1\"", \
winid, r, NULL }}


/* search engines */
static char *searchengine = "https://www.google.com/search?q=";
static const char * defaultsearchengine = "https://www.google.co.uk/search?q=%s";
static SearchEngine searchengines[] = {
/* Search Engines */
  { "bi=", "https://www.bing.com/search?q=%s" },
  { "br=", "https://search.brave.com/search?q=%s" },
  { "du=", "https://duckduckgo.com/?q=%s" },
  { "go=", "https://www.google.com/search?q=%s" },
  { "le=", "https://dict.leo.org/ende?search=%s" },
  { "qw=", "https://www.qwant.com/?q=%s" },
  { "sw=", "https://swisscows.com/web?query=%s" },
  { "ya=", "https://yandex.com/search/?text=%s" },
/* Information/News */
  { "bb=", "https://www.bbc.co.uk/search?q=%s" },
  { "cn=", "https://www.cnn.com/search?q=%s" },
  { "gn=", "https://news.google.com/search?q=%s" },
  { "wp=", "https://en.wikipedia.org/w/index.php?search=%s" },
  { "wt=", "https://en.wiktionary.org/w/index.php?search=%s" },
/* Social Media */
  { "re=", "https://www.reddit.com/search/?q=%s" },
  { "od=", "https://odysee.com/$/search?q=%s" },
  { "yo=", "https://www.youtube.com/results?search_query=%s" },
/* Online Shopping */
  { "am=", "https://www.amazon.com/s?k=%s" },
  { "cr=", "https://www.craigslist.org/search/sss?query=%s" },
  { "eb=", "https://www.ebay.com/sch/i.html?&_nkw=%s" },
  { "gu=", "https://www.gumtree.com/search?search_category=all&q=%s" },
/* Linux */
  { "aa=", "https://aur.archlinux.org/packages/?O=0&K=%s" },
  { "ap=", "https://archlinux.org/packages/?sort=&q=%s" },
  { "aw=", "https://wiki.archlinux.org/index.php?search=%s" },
  { "dp=", "https://packages.debian.org/search?suite=default&section=all&arch=any&searchon=names&keywords=%s" },
/* Development */
  { "gh=", "https://github.com/search?q=%s" },
  { "gl=", "https://gitlab.com/search?search=%s" },
  { "os=", "https://opensource.google/projects/search?q=%s" },
  { "sf=", "https://sourceforge.net/directory/?q=%s" },
  { "so=", "https://stackoverflow.com/search?q=%s" },
};


/* styles */
/*
 * The iteration will stop at the first match, beginning at the beginning of
 * the list.
 */
static SiteSpecific styles[] = {
  /* regexp                   file in $styledir */
  { ".*archlinux.org.*",     "archlinux.css" },
  { ".*suckless.org.*",      "suckless.css" },
  { ".*wikipedia.org.*",     "wikipedia.css" },
  { ".*youtube.com.*",       "youtube.css" },
  { ".*github.com.*",        "github.css" },
  { ".*sw.kovidgoyal.net.*", "kitty.css" },
  { ".*",                    "default.css" },
};


/* certificates */
/*
 * Provide custom certificate for urls
 */
static SiteSpecific certs[] = {
  /* regexp               file in $certdir */
  { "://suckless\\.org/", "suckless.org.crt" },
};


/* hotkeys */
#define MODKEY GDK_CONTROL_MASK
/*
 * If you use anything else but MODKEY and GDK_SHIFT_MASK, don't forget to
 * edit the CLEANMASK() macro.
 */
static Key keys[] = {
  /* modifier              keyval          function            arg */
  { MODKEY,                GDK_KEY_m,      spawn,              BM_ADD("_SURF_URI") },
  { MODKEY,                GDK_KEY_g,      spawn,              SETPROP("_SURF_URI", "_SURF_GO", PROMPT_GO) },

  { MODKEY,                GDK_KEY_f,      spawn,              SETPROP("_SURF_FIND", "_SURF_FIND", PROMPT_FIND) },
  { MODKEY,                GDK_KEY_slash,  spawn,              SETPROP("_SURF_FIND", "_SURF_FIND", PROMPT_FIND) },
  { MODKEY,                GDK_KEY_n,      find,               { .i = +1 } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_n,      find,               { .i = -1 } },

  { MODKEY,                GDK_KEY_s,      stop,               { 0 } },
  { MODKEY,                GDK_KEY_q,      quit,               { 0 } },

  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_r,      reload,             { .i = 1 } },
  { MODKEY,                GDK_KEY_r,      reload,             { .i = 0 } },

  { MODKEY,                GDK_KEY_l,      navigate,           { .i = +1 } },
  { MODKEY,                GDK_KEY_h,      navigate,           { .i = -1 } },

  { MODKEY,                GDK_KEY_j,      scrollv,            { .i = +10 } },
  { MODKEY,                GDK_KEY_k,      scrollv,            { .i = -10 } },
  { MODKEY,                GDK_KEY_space,  scrollv,            { .i = +50 } },
  { MODKEY,                GDK_KEY_b,      scrollv,            { .i = -50 } },
  { MODKEY,                GDK_KEY_i,      scrollh,            { .i = +10 } },
  { MODKEY,                GDK_KEY_u,      scrollh,            { .i = -10 } },

  { MODKEY,                GDK_KEY_Down,   zoom,               { .i = -1 } },
  { MODKEY,                GDK_KEY_Up,     zoom,               { .i = +1 } },
  { MODKEY,                GDK_KEY_space,  zoom,               { .i = 0  } },

  { MODKEY,                GDK_KEY_p,      clipboard,          { .i = 1 } },
  { MODKEY,                GDK_KEY_y,      clipboard,          { .i = 0 } },

  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_p,      print,              { 0 } },
  { MODKEY,                GDK_KEY_t,      showcert,           { 0 } },


  { 0,                     GDK_KEY_F1,     externalpipe,       { .v = openhelp } },
  { 0,                     GDK_KEY_F2,     externalpipe,       { .v = editbookmarks } },
  { 0,                     GDK_KEY_F4,     playexternal,       { 0 } },
  { 0,                     GDK_KEY_F5,     spawndls,           { 0 } },
  { 0,                     GDK_KEY_F6,     spawn,              SETURI("_SURF_GO") },
  { 0,                     GDK_KEY_F7,     externalpipe,       { .v = linkselect_curwin } },
  { 0,                     GDK_KEY_F8,     externalpipe,       { .v = linkselect_newwin } },
  { 0,                     GDK_KEY_F9,     externalpipe,       { .v = editscreen } },
  { 0,                     GDK_KEY_F10,    togglecookiepolicy, { 0 } },
  { 0,                     GDK_KEY_F11,    togglefullscreen,   { 0 } },
  { 0,                     GDK_KEY_F12,    toggleinspector,    { 0 } },

  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_c,      toggle,             { .i = CaretBrowsing } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_f,      toggle,             { .i = FrameFlattening } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_g,      toggle,             { .i = Geolocation } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_s,      toggle,             { .i = JavaScript } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_i,      toggle,             { .i = LoadImages } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_b,      toggle,             { .i = ScrollBars } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_t,      toggle,             { .i = StrictTLS } },
  { MODKEY|GDK_SHIFT_MASK, GDK_KEY_m,      toggle,             { .i = Style } },
};


/* button definitions */
/* target can be OnDoc, OnLink, OnImg, OnMedia, OnEdit, OnBar, OnSel, OnAny */
static Button buttons[] = {
  /* target       event mask      button  function           argument        stop event */
  { OnLink,       0,              2,      clicknewwindow,    { .i = 0 },     1 },
  { OnLink,       MODKEY,         2,      clicknewwindow,    { .i = 1 },     1 },
  { OnLink,       MODKEY,         1,      clicknewwindow,    { .i = 1 },     1 },
  { OnAny,        0,              8,      clicknavigate,     { .i = -1 },    1 },
  { OnAny,        0,              9,      clicknavigate,     { .i = +1 },    1 },
  { OnMedia,      MODKEY,         1,      clickexternplayer, { 0 },          1 },
};

