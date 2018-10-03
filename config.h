/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 2;        /* gap pixel between windows */
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
static const char col_cyan[]        = "#215d9c";
static const char *colors[][3]      = {
	/*                fg         bg         border   */
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray2 },
	[SchemeUnsel] = { col_gray3, col_gray0, col_gray2 },
	[SchemeSel]   = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "imv",      NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[+]",      tileleft },
	{ "[+]",      tileright },
	{ "[+]",      tileup },
	{ "[+]",      tiledown },
	{ "[0]",      monocle },
	{ "[ ]",      NULL },
};

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
static const char *dmenucmd[] = { "/home/suphi/Documents/Scripts/dmenu-custom.sh", "-b", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
/* custom commands */
static const char *browsercmd[] = { "chromium", NULL };
static const char *filecmd[] = { "thunar", NULL };
static const char *editorcmd[] = { "mousepad", NULL };
static const char *mediacmd[] = { "parole", NULL };
static const char *colorcmd[] = { "gpick", "-p", NULL };
static const char *playcmd[] = { "pragha", "-t", NULL };
static const char *stopcmd[] = { "pragha", "-s", NULL };
static const char *prevcmd[] = { "pragha", "-r", NULL };
static const char *nextcmd[] = { "pragha", "-n", NULL };
static const char *calculatorcmd[] = { "galculator", NULL };
static const char *printscreencmd[]  = { "sh", "-c", "maim ~/Pictures/$(date +%s).png", NULL };
static const char *printwindowcmd[]  = { "sh", "-c", "maim -i $(xdotool getactivewindow) ~/Pictures/$(date +%s).png", NULL };
static const char *backlightdowncmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/backlight.sh -5%", NULL };
static const char *backlightupcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/backlight.sh +5%", NULL };
static const char *touchpadcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/touchpad.sh", NULL };
static const char *touchpadresetcmd[] = { "sh", "-c", "~/Documents/Scripts/reset-touchpad.sh", NULL };
static const char *volumemutecmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/mute.sh toggle", NULL };
static const char *volumedowncmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/volume.sh -5%", NULL };
static const char *volumeupcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/volume.sh +5%", NULL };
static const char *connectwirelesscmd[] = { "sh", "-c", "sudo ~/Documents/Scripts/DynamicStatus/wireless.sh", NULL };
static const char *simplestatuscmd[] = { "dstatus", "s", "60", "~/Documents/Scripts/DynamicStatus/simple.sh", NULL };
static const char *advancedstatuscmd[] = { "dstatus", "s", "1", "~/Documents/Scripts/DynamicStatus/advanced.sh", NULL };


static Key keys[] = {
	/* modifier                     key                       function        argument */
	{ 0,                            XF86XK_MonBrightnessDown, spawn,          {.v = backlightdowncmd } },
	{ 0,                            XF86XK_MonBrightnessUp,   spawn,          {.v = backlightupcmd } },
	{ 0,                            XF86XK_TouchpadToggle,    spawn,          {.v = touchpadcmd } },
	{ 0,                            XF86XK_AudioMute,         spawn,          {.v = volumemutecmd } },
	{ 0,                            XF86XK_AudioLowerVolume,  spawn,          {.v = volumedowncmd } },
	{ 0,                            XF86XK_AudioRaiseVolume,  spawn,          {.v = volumeupcmd } },
	{ 0,                            XF86XK_AudioPlay,         spawn,          {.v = playcmd } },
	{ 0,                            XF86XK_AudioStop,         spawn,          {.v = stopcmd } },
	{ 0,                            XF86XK_AudioPrev,         spawn,          {.v = prevcmd } },
	{ 0,                            XF86XK_AudioNext,         spawn,          {.v = nextcmd } },
	{ 0,                            XF86XK_WWW,               spawn,          {.v = touchpadresetcmd } },
	{ 0,                            XF86XK_Launch1,           spawn,          {.v = connectwirelesscmd } },
	{ 0,                            XF86XK_WebCam,            spawn,          {.v = connectwirelesscmd } },
	{ 0,                            XK_Menu,                  spawn,          {.v = dmenucmd } },
	{ 0,                            XK_Print,                 spawn,          {.v = printscreencmd } },
	{ 0|ShiftMask,                  XK_Print,                 spawn,          {.v = printwindowcmd } },
	{ MODKEY,                       XK_t,                     spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,                     spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_f,                     spawn,          {.v = filecmd } },
	{ MODKEY,                       XK_e,                     spawn,          {.v = editorcmd } },
	{ MODKEY,                       XK_m,                     spawn,          {.v = mediacmd } },
	{ MODKEY,                       XK_c,                     spawn,          {.v = calculatorcmd } },
	{ MODKEY,                       XK_p,                     spawn,          {.v = colorcmd } },
	{ MODKEY|ShiftMask,             XK_s,                     spawn,          {.v = simplestatuscmd } },
	{ MODKEY|ShiftMask,             XK_a,                     spawn,          {.v = advancedstatuscmd } },
	/* modifier                     key                       function        argument */
	{ MODKEY|ShiftMask,             XK_b,                     togglebar,      {0} },
	{ MODKEY,                       XK_space,                 togglefloating, {.i = 40} },
	{ MODKEY,                       XK_Down,                  actiondown,     {.i = 0} },
	{ MODKEY|ShiftMask,             XK_Down,                  actiondown,     {.i = 1} },
	{ MODKEY|ControlMask,           XK_Down,                  setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_Left,                  actionleft,     {.i = 0} },
	{ MODKEY|ShiftMask,             XK_Left,                  actionleft,     {.i = 1} },
	{ MODKEY|ControlMask,           XK_Left,                  setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_Right,                 actionright,    {.i = 0} },
	{ MODKEY|ShiftMask,             XK_Right,                 actionright,    {.i = 1} },
	{ MODKEY|ControlMask,           XK_Right,                 setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_Up,                    actionup,       {.i = 0} },
	{ MODKEY|ShiftMask,             XK_Up,                    actionup,       {.i = 1} },
	{ MODKEY|ControlMask,           XK_Up,                    setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_Return,                zoom,           {0} },
	{ MODKEY|ControlMask,           XK_Return,                setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_Page_Down,             focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Page_Down,             tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_Page_Up,               focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Page_Up,               tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_0,                     view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                     tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Tab,                   view,           {0} },
	{ MODKEY|ShiftMask,             XK_Tab,                   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_bracketleft,           setgap,         {.i = -2 } },
	{ MODKEY|ShiftMask,             XK_bracketright,          setgap,         {.i = +2 } },
	{ MODKEY,                       XK_Escape,                killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_Escape,                quit,           {0} },
	TAGKEYS(                        XK_1,                                     0)
	TAGKEYS(                        XK_2,                                     1)
	TAGKEYS(                        XK_3,                                     2)
	TAGKEYS(                        XK_4,                                     3)
	TAGKEYS(                        XK_5,                                     4)
	TAGKEYS(                        XK_6,                                     5)
	TAGKEYS(                        XK_7,                                     6)
	TAGKEYS(                        XK_8,                                     7)
	TAGKEYS(                        XK_9,                                     8)
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
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

