/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx    = 1;        /* border pixel of windows */
static const unsigned int snap        = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating      = 0;        /* 1 means swallow floating windows by default */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 1;        /* 0 means bottom bar */
static const char *fonts[]            = { "CaskaydiaCove Nerd Font Mono:size=10",
                                          "IPAPGothic:size=11"
                                        };
static const char dmenufont[]         =   "CaskaydiaCove Nerd Font Mono:size=10"  ;
static const char col_gray1[]         = "#222222";
static const char col_gray2[]         = "#444444";
static const char col_gray3[]         = "#bbbbbb";
static const char col_gray4[]         = "#eeeeee";
static const char col_cyan[]          = "#005577";
static const unsigned int baralpha    = 0x60;
static const unsigned int borderalpha = OPAQUE;

static const char *colors[][3]        = {
	/*                     fg         bg         border   */
	[SchemeNorm]       = { "#000000", "#029c91", col_gray2 }, 
	[SchemeSel]        = { "#000000", "#00b35a",  col_cyan  }, 
    [SchemeStatus]     = { "#000000", "#029c91", "#000000" }, // statusbar right
    [SchemeTagsSel]    = { "#000000", "#00b35a",  "#000000" }, // tagsbar left
    [SchemeTagsNorm]   = { "#000000", "#029c91", "#000000" },
    [SchemeInfoSel]    = { "#000000", "#029c91",  "#000000" }, // infobar middle
    [SchemeInfoNorm]   = { "#000000", "#029c91", "#000000" },
};

static const unsigned int alphas[][3] = {
    /*                     fg          bg         border      */
    [SchemeNorm]       = { OPAQUE,     baralpha,  borderalpha },
    [SchemeSel]        = { OPAQUE,     baralpha,  borderalpha },
    [SchemeTagsSel]    = { OPAQUE,     baralpha,  borderalpha }, // tagsbar left
    [SchemeTagsNorm]   = { OPAQUE,     baralpha,  borderalpha },
    [SchemeInfoSel]    = { OPAQUE,     baralpha,  borderalpha }, // infobar middle
    [SchemeInfoNorm]   = { OPAQUE,     baralpha,  borderalpha },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
const char *spcmd4[] = {"st", "-n", "spmp", "-g", "144x41", "-e", "ncmpcpp", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
    {"spncmpcpp",   spcmd4},
};
                                                                                   
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const char ptagf[] = "[%s %s]"; /* format of a tag label */
static const char etagf[] = "[%s]"; /* format of an empty tag */
static const int lcaselbl = 0;     /* 1 means make tag label lowercase */




static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",      NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "LibreWolf", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
    { "librewolf", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "st",        NULL,     NULL,           0,         0,          1,           0,        -1 },
    { "discord",   NULL,     NULL,           1 << 5,    0,          0,          -1,        -1 },

    { NULL,        NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
   
    { NULL,		   "spterm",		NULL,		SPTAG(0),		1, 0, 1,			 -1 },
    { NULL,		   "spfm",		NULL,		SPTAG(1),		1, 0, 1			 -1 },
    { NULL,		   "keepassxc",	NULL,		SPTAG(2),		1, 0, 1			 -1 },
    { NULL,        "spmp",  NULL,       SPTAG(3),       1, 0, 1,         -1 },



};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* Vanitygaps includes many of these already, so comment out all don't need */

// #include "layouts/fibonacci.c"
// #include "layouts/bstack.c"
// #include "layouts/centeredmaster.c"
#include "layouts/tatami.c"
// #include "layouts/layouts.c"
// #include "layouts/gaplessgrid.c"
// #include "layouts/horizgrid.c"
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "[@]",      spiral },
    { "[\\]",     dwindle },
    { "|+|",      tatami },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "HHH",      grid },
    { ":::",      gaplessgrid }, 
    { "---",      horizgrid },   
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
    { Mod4Mask|ShiftMask,           KEY,      swaptags,       {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *slockcmd[] = { "slock", NULL };

// Commands to change volume
static const char *audioupcmd[] = { "change-audio", "2dB+", "unmute" };
static const char *audiodncmd[] = { "change-audio", "2dB-", "unmute" };
static const char *audiomtcmd[] = { "change-audio", "toggle" };

// Commands to change brightness
static const char *lightupcmd[] = { "change-light", "dec", "5" };
static const char *lightdncmd[] = { "change-light", "inc", "5" };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_l,      spawn,          {.v = slockcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },

    /* vanitygaps */
	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

    /* Set layouts */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
    { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[5]} },
    { MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[6]} },
    // { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[7]} },
    // { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[8]} },
    // { MODKEY|ShiftMask,             XK_o,      setlayout,      {.v = &layouts[9]} },
    // { MODKEY,                       XK_g,      setlayout,      {.v = &layouts[10]} },
    // { MODKEY|ShiftMask,             XK_g,      setlayout,      {.v = &layouts[11]} },
    // { MODKEY|ShiftMask,             XK_h,      setlayout,      {.v = &layouts[12]} },

    /* Scratchpads */
    { MODKEY,                       XK_z,      togglescratch,  {.ui = 0 } },
    { MODKEY,                       XK_x,      togglescratch,  {.ui = 1 } },
    { MODKEY,                       XK_c,      togglescratch,  {.ui = 2 } },
    { MODKEY,                       XK_v,      togglescratch,  {.ui = 3 } },

    /* Shortcuts - Audio */
    { MODKEY,                       XK_F5,     spawn,          {.v = audiodncmd } },
    { MODKEY,                       XK_F6,     spawn,          {.v = audioupcmd } },
    { MODKEY,                       XK_F3,     spawn,          {.v = audiomtcmd } },

    /* Shortcuts - Brightness */
    { MODKEY,                       XK_F8,     spawn,          {.v = lightupcmd } },
    { MODKEY,                       XK_F9,     spawn,          {.v = lightdncmd } },


	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

