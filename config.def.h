/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gap pixel between windows */
static const unsigned int marginpx  = 16;       /* margin pixel around windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray0[]       = "#111111";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#cccccc";
static const char col_gray4[]       = "#ffffff";
static const char col_blue[]        = "#215d9c";
static const char *colors[][3]      = {
	/*                fg         bg         border   */
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray2 },
	[SchemeUnsel] = { col_gray3, col_gray0, col_gray2 },
	[SchemeSel]   = { col_gray4, col_blue,  col_blue  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

/* first entry is default */
/* NULL layout function means floating behavior */
static const Layout layouts[] = { { tileleft }, { tileright }, { tileup }, { tiledown }, { monocle }, { NULL } };

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_blue, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier              key                 function           argument */
	{ 0,                     XK_Menu,            spawn,             {.v = dmenucmd } },
	{ MODKEY,                XK_t,               spawn,             {.v = termcmd } },
	{ MODKEY,                XK_Shift_R,         togglebar,         {0} },
	{ MODKEY,                XK_space,           togglefloating,    {.i = 32} },
	{ MODKEY,                XK_Down,            actiondown,        {.i = 0} },
	{ MODKEY|ShiftMask,      XK_Down,            actiondown,        {.i = 1} },
	{ MODKEY|ControlMask,    XK_Down,            setlayout,         {.v = &layouts[3]} },
	{ MODKEY,                XK_Left,            actionleft,        {.i = 0} },
	{ MODKEY|ShiftMask,      XK_Left,            actionleft,        {.i = 1} },
	{ MODKEY|ControlMask,    XK_Left,            setlayout,         {.v = &layouts[0]} },
	{ MODKEY,                XK_Right,           actionright,       {.i = 0} },
	{ MODKEY|ShiftMask,      XK_Right,           actionright,       {.i = 1} },
	{ MODKEY|ControlMask,    XK_Right,           setlayout,         {.v = &layouts[1]} },
	{ MODKEY,                XK_Up,              actionup,          {.i = 0} },
	{ MODKEY|ShiftMask,      XK_Up,              actionup,          {.i = 1} },
	{ MODKEY|ControlMask,    XK_Up,              setlayout,         {.v = &layouts[2]} },
	{ MODKEY,                XK_Return,          zoom,              {0} },
	{ MODKEY|ControlMask,    XK_Return,          setlayout,         {.v = &layouts[4]} },
	{ MODKEY,                XK_Page_Down,       focusmon,          {.i = -1 } },
	{ MODKEY|ShiftMask,      XK_Page_Down,       tagmon,            {.i = -1 } },
	{ MODKEY,                XK_Page_Up,         focusmon,          {.i = +1 } },
	{ MODKEY|ShiftMask,      XK_Page_Up,         tagmon,            {.i = +1 } },
	{ MODKEY,                XK_0,               view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,      XK_0,               tag,               {.ui = ~0 } },
	{ MODKEY,                XK_Tab,             view,              {0} },
	{ MODKEY|ShiftMask,      XK_Tab,             setlayout,         {0} },
	{ MODKEY,                XK_bracketleft,     setgap,            {.i = -2 } },
	{ MODKEY,                XK_bracketright,    setgap,            {.i = +2 } },
	{ MODKEY|ShiftMask,      XK_bracketleft,     setmargin,         {.i = -2 } },
	{ MODKEY|ShiftMask,      XK_bracketright,    setmargin,         {.i = +2 } },
	{ MODKEY,                XK_Escape,          killclient,        {0} },
	{ MODKEY|ShiftMask,      XK_Escape,          quit,              {0} },
	TAGKEYS(                 XK_1,                                  0)
	TAGKEYS(                 XK_2,                                  1)
	TAGKEYS(                 XK_3,                                  2)
	TAGKEYS(                 XK_4,                                  3)
	TAGKEYS(                 XK_5,                                  4)
	TAGKEYS(                 XK_6,                                  5)
	TAGKEYS(                 XK_7,                                  6)
	TAGKEYS(                 XK_8,                                  7)
	TAGKEYS(                 XK_9,                                  8)
};

/* button definitions */
/* click can be ClkTagBar, ClkWinTitle, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button1,        zoom,           {0} },
	{ ClkWinTitle,          0,              Button3,        killclient,     {0} },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {.i = 32} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

