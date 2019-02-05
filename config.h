/* See LICENSE file for copyright and license details. */
//      _
//   __| |_      ___ __ ___
//  / _` \ \ /\ / / '_ ` _ \
// | (_| |\ V  V /| | | | | |:Ahmed's dwm config.h:
//  \__,_| \_/\_/ |_| |_| |_|:ahmed_khaledATzohoDoTCoM:
// ┏┓╻╻ ╻
// ┃┗┫╺╋╸
// ╹ ╹╹ ╹


/* appearance */
static const char *fonts[] = {"DejaVu Sans Mono:size=10"};
static const char dmenufont[] = "monospace:size=10";
static const unsigned int borderpx = 2;  /* border pixel of windows */
static const unsigned int gappx    = 2;  /* gap pixel between windows */
static const unsigned int marginpx = 0;  /* margin pixel around windows */
static const unsigned int snap     = 32; /* snap pixel */
static const int showbar           = 1;  /* 0 means no bar */
static const int topbar            = 1;  /* 0 means bottom bar */
static const char col_gray0[]  = "#111111";
static const char col_gray1[]  = "#222222";
static const char col_gray2[]  = "#444444";
static const char col_gray3[]  = "#cccccc";
static const char col_gray4[]  = "#ffffff";
static const char col_blue[]   = "#215d9c";
static const char *colors[][3] = {
    /*                fg         bg         border   */
    [SchemeNorm]  = {col_gray3 , col_gray1 , col_gray2} ,
    [SchemeUnsel] = {col_gray3 , col_gray0 , col_gray2} ,
    [SchemeSel]   = {col_gray4 , col_blue  , col_blue}  ,
};
static const char normbordercolor[]      = "#444444";
static const char normbgcolor[]          = "#000000";
static const char normfgcolor[]          = "#bbbbbb";
static const char selbordercolor[]       = "#8ff975";
static const char selbgcolor[]           = "#000000";
static const char selfgcolor[]           = "#eeeeee";
static const char floatnormbordercolor[] = "#444444";
static const char floatselbordercolor[]  = "#8ff975";

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     *
     * class            instance     title           tags mask     isfloating
     * monitor */
    {"St"          , "st"          , "dropdown" , 0 , 1 , -1} ,
    {"st-256color" , "st-256color" , "dropdown" , 0 , 1 , -1} ,
    {"URxvt"       , "urxvt"       , "dropdown" , 0 , 1 , -1} ,
};

/* layout(s) */
static const float mfact = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */

/* first entry is default */
/* NULL layout function means floating behavior */
static const Layout layouts[] = {{tileleft}, {tileright}, {tileup},
                                 {tiledown}, {monocle},   {NULL}};

/* key definitions */
#define MOD4     Mod4Mask
#define CONTROL  ControlMask /* Control key */
#define SHIFT    ShiftMask     /* Shift key */
#define DOWNKEY  XK_j
#define LEFTKEY  XK_h
#define RIGHTKEY XK_l
#define UPKEY    XK_k
#define TAGKEYS(KEY, TAG)                                                  \
      {MOD4                       , KEY , view       , {.ui = 1 << TAG}} , \
      {MOD4|ControlMask           , KEY , toggleview , {.ui = 1 << TAG}} , \
      {MOD4|ShiftMask             , KEY , tag        , {.ui = 1 << TAG}} , \
      {MOD4|ControlMask|ShiftMask , KEY , toggletag  , {.ui = 1 << TAG}} ,

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "/home/suphi/Documents/Scripts/dmenu-custom.sh", "-b", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_blue, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = {"dmenu_run", "-m",  dmenumon,    "-fn",
                                 dmenufont,   "-nb", normbgcolor, "-nf",
                                 normfgcolor, "-sb", selbgcolor,  "-sf",
                                 selfgcolor,  NULL};
static const char *dmenucmd2[] = { "dmenu_run", "-b", "-i", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_blue, "-sf", col_gray4, NULL };
//static const char *termcmd[]  = { "urxvt", NULL };
static const char *termcmd[] = {"st", NULL};
/* custom commands */
//static const char *browsercmd[] = { "chromium", NULL };
//static const char *filecmd[] = { "thunar", NULL };
//static const char *editorcmd[] = { "mousepad", NULL };
//static const char *mediacmd[] = { "parole", NULL };
//static const char *colorcmd[] = { "gpick", "-p", NULL };
//static const char *playcmd[] = { "pragha", "-t", NULL };
//static const char *stopcmd[] = { "pragha", "-s", NULL };
//static const char *prevcmd[] = { "pragha", "-r", NULL };
//static const char *nextcmd[] = { "pragha", "-n", NULL };
//static const char *calculatorcmd[] = { "galculator", NULL };
//static const char *printscreencmd[]  = { "sh", "-c", "maim ~/Pictures/$(date +%s).png", NULL };
//static const char *printwindowcmd[]  = { "sh", "-c", "maim -i $(xdotool getactivewindow) ~/Pictures/$(date +%s).png", NULL };
//static const char *backlightdowncmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/backlight.sh -5%", NULL };
//static const char *backlightupcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/backlight.sh +5%", NULL };
//static const char *touchpadcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/touchpad.sh", NULL };
//static const char *touchpadresetcmd[] = { "sh", "-c", "~/Documents/Scripts/reset-touchpad.sh", NULL };
//static const char *volumemutecmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/mute.sh toggle", NULL };
//static const char *volumedowncmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/volume.sh -5%", NULL };
//static const char *volumeupcmd[] = { "sh", "-c", "~/Documents/Scripts/DynamicStatus/volume.sh +5%", NULL };
//static const char *connectwirelesscmd[] = { "sh", "-c", "sudo ~/Documents/Scripts/DynamicStatus/wireless.sh", NULL };
//static const char *simplestatuscmd[] = { "dstatus", "s", "60", "~/Documents/Scripts/DynamicStatus/simple.sh", NULL };
//static const char *advancedstatuscmd[] = { "dstatus", "s", "1", "~/Documents/Scripts/DynamicStatus/advanced.sh", NULL };
//static const char *localhostcmd[] = { "surf", "http://localhost:7681", NULL };

static Key keys[] = {
	/* modifier                      key               function           argument */
	{ MOD4,                          DOWNKEY,          actiondown,        {.i = 0} },
	{ MOD4|ShiftMask,                DOWNKEY,          actiondown,        {.i = 1} },
	{ MOD4|ControlMask,              DOWNKEY,          actiondown,        {.i = 2} },
	{ MOD4|ControlMask|ShiftMask,    DOWNKEY,          setlayout,         {.v = &layouts[3]} },
	{ MOD4,                          LEFTKEY,          actionleft,        {.i = 0} },
	{ MOD4|ShiftMask,                LEFTKEY,          actionleft,        {.i = 1} },
	{ MOD4|ControlMask,              LEFTKEY,          actionleft,        {.i = 2} },
	{ MOD4|ControlMask|ShiftMask,    LEFTKEY,          setlayout,         {.v = &layouts[0]} },
	{ MOD4,                          RIGHTKEY,         actionright,       {.i = 0} },
	{ MOD4|ShiftMask,                RIGHTKEY,         actionright,       {.i = 1} },
	{ MOD4|ControlMask,              RIGHTKEY,         actionright,       {.i = 2} },
	{ MOD4|ControlMask|ShiftMask,    RIGHTKEY,         setlayout,         {.v = &layouts[1]} },
	{ MOD4,                          UPKEY,            actionup,          {.i = 0} },
	{ MOD4|ShiftMask,                UPKEY,            actionup,          {.i = 1} },
	{ MOD4|ControlMask,              UPKEY,            actionup,          {.i = 2} },
	{ MOD4|ControlMask|ShiftMask,    UPKEY,            setlayout,         {.v = &layouts[2]} },
  { MOD4,                          XK_d,             spawn,             {.v = dmenucmd } },
  { MOD4,                          XK_Return,        spawn,             {.v = termcmd } },
  { MOD4,                          XK_Shift_R,       togglebar,         {0} },
  { MOD4,                          XK_o,             incnmaster,        {.i = +1 } },
  { MOD4,                          XK_p,             incnmaster,        {.i = -1 } },
  { MOD4,                          XK_Tab,           view,              {0} },
  { MOD4,                          XK_t,             setlayout,         {.v = &layouts[0]} },
  { MOD4,                          XK_f,             setlayout,         {.v = &layouts[1]} },
  { MOD4,                          XK_m,             togglemonocle,     {0} },
  { MOD4|SHIFT,                    XK_space,         setlayout,         {0} },
  { MOD4,                          XK_space,         togglefloating,    {0} },
  // Gaps
  { MOD4,                          XK_bracketleft,   setgap,            {.i = -2 } },
  { MOD4,                          XK_bracketright,  setgap,            {.i = +2 } },
  { MOD4|ShiftMask,                XK_bracketleft,   setmargin,         {.i = -2 } },
  { MOD4|ShiftMask,                XK_bracketright,  setmargin,         {.i = +2 } },
  { MOD4,                          XK_0,             view,              {.ui = ~0 } },
  { MOD4|SHIFT,                    XK_0,             tag,               {.ui = ~0 } },
  { MOD4,                          XK_comma,         focusmon,          {.i = -1 } },
  { MOD4,                          XK_period,        focusmon,          {.i = +1 } },
  { MOD4|SHIFT,                    XK_comma,         tagmon,            {.i = -1 } },
  { MOD4|SHIFT,                    XK_period,        tagmon,            {.i = +1 } },
  { MOD4,                          XK_q,             killclient,        {0} },
  { MOD4|CONTROL,                  XK_q,             quit,              {0} },
  TAGKEYS(                         XK_1,                                 0)
  TAGKEYS(                         XK_2,                                 1)
  TAGKEYS(                         XK_3,                                 2)
  TAGKEYS(                         XK_4,                                 3)
  TAGKEYS(                         XK_5,                                 4)
  TAGKEYS(                         XK_6,                                 5)
  TAGKEYS(                         XK_7,                                 6)
  TAGKEYS(                         XK_8,                                 7)
  TAGKEYS(                         XK_9,                                 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkWinTitle, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MOD4,           Button1,        tag,            {0} },
	{ ClkTagBar,            MOD4,           Button3,        toggletag,      {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = simplestatuscmd } },
	{ ClkStatusText,        0,              Button3,        spawn,          {.v = advancedstatuscmd } },
	{ ClkClientWin,         MOD4,           Button1,        movemouse,      {0} },
	{ ClkClientWin,         MOD4,           Button3,        resizemouse,    {0} },
};
