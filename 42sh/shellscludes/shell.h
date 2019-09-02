/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <apsaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:27:56 by pharatyk          #+#    #+#             */
/*   Updated: 2019/08/20 13:06:56 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libmaster.h"
# include <signal.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/ioctl.h>

# include <term.h>

# define MAX_FD 8192
# define HIST_SIZE 32442
# define OPT_L 1
# define OPT_N 2
# define OPT_R 4
# define OPT_E 8
# define OPT_S 16
# define REDIR_ERR 2

typedef struct	s_preult
{
	char				**tablor;
	int					*indexor;
	double				*ftabor;
}				t_preult;

typedef struct	s_process
{
	pid_t				pid;
	int					status;
	int					ret;
	int					stopped;
	int					completed;
	char				*cmd;
	struct s_process	*next;
}				t_process;

typedef struct	s_palten
{
	int					j;
	int					incbef;
	int					incaft;
	char				*hope;
	char				*test;
}				t_palten;

typedef struct	s_job
{
	pid_t				pgid;
	int					ret;
	int					notif;
	int					in_fg;
	int					pipe;
	int					job_nb;
	char				plus_minus;
	struct s_process	*fst_process;
	struct s_job		*next;
}				t_job;

typedef struct	s_lcalc
{
	char			*word;
	char			*number;
	struct s_lcalc	*next;
}				t_lcalc;

typedef struct	s_tmper
{
	int			part1;
	int			part2;
	char		*part3;
}				t_tmper;

typedef struct	s_fcter
{
	int			i;
	int			stop;
}				t_fcter;

typedef struct	s_alias
{
	char			*alias;
	char			*name;
	int				statut;
	struct s_alias	*next;
}				t_alias;

typedef struct	s_masterenv
{
	int			rep[5];
	int			repe[5];
	char		***stock;
	char		***internal_var;
	char		**cgv;
	int			*cgtype;
	int			*cgprio;
	int			cgc;
	int			fg;
	int			cdopt;
	int			cdpath;
	int			nruter;
	int			pipe;
	t_alias		*als;
	int			pals;
	int			changeals;
	char		*fcp;
	char		***fcts;
	char		***inenv;
	int			valfct;
	int			neight;
	int			mode;
}				t_masterenv;

typedef struct	s_nbtool
{
	int			nb;
	int			flag;
	int			parf;
	int			sparf;
	int			dparf;
	int			cpt;
	int			j;
	int			par;
}				t_nbtool;

typedef struct	s_calctools
{
	char		**stuff;
	char		*tmp;
	int			*digit;
	double		*flts;
	char		*answ;
	int			pos;
	int			flag;
	int			nb;
	int			inc;
	int			tobegin;
	int			isflt;
}				t_calctools;

typedef struct	s_echotools
{
	int			i;
	int			j;
	int			nope;
	int			flag;
	int			nonstop;
}				t_echotools;

typedef struct	s_trouvtrouss
{
	int		nb;
	int		nope;
	int		warning;
	int		nozero;
	int		nomore;
	int		gg;
}				t_trouvtrouss;

typedef struct	s_hist
{
	int		count;
	char	**cmdhist;
	char	*usercmd;
	char	*histfile;
	int		index;
	int		n;
	int		fc;
}				t_hist;

typedef struct	s_stockap
{
	int		nbline;
	int		nbcol;
	char	*ec_cap;
	char	*left_cap;
	char	*right_cap;
	char	*up_cap;
	char	*down_cap;
	char	*dl_cap;
	char	*savecurs_cap;
	char	*backurs_cap;
	char	*cl_cap;
	char	*us_cap;
	char	*me_cap;
	char	*mb_cap;
	char	*md_cap;
	char	*cm_cap;
	char	*ti_cap;
	char	*rv_cap;
	char	*cd_cap;
}				t_stockap;

typedef struct	s_stock
{
	char	**output;
	int		select;
	int		*valid;
	int		argc;
}				t_stock;

typedef struct	s_keymaster
{
	char	buf[256];
	char	bigbuf[256];
	t_hist	hist;
	char	*prompt;
	int		promptsize;
	char	*out;
	int		lenout;
	int		curspos;
	int		index;
	int		lvl;
	char	*sep;
	char	*pathfile;
	int		herelvl;
	int		first;
	int		new_lvl;
	int		lastprompt;
	int		selectmode;
	int		heremode;
	int		search;
	int		selpiv;
	char	*presspap;
	int		aukprinted;
	t_stock	stock;
	char	**contdir;
	char	*complete;
	char	*fullname;
	char	*tmp;
	char	*final;
	int		nb_auto;
	char	***fcts;
	char	***inenv;
	pid_t	shell_pgid;
	int		nb_job;
	char	*rechist;
	int		exp;
	int		opt;
}				t_keymaster;

typedef struct	s_basiks
{
	int		max;
	int		nbobj;
	int		nbligne;
	int		lignemax;
}				t_basiks;

typedef struct	s_ijer
{
	int		i;
	int		j;
}				t_ijer;

char			*g_ultib;
struct termios	g_shell_attr;
pid_t			g_pid;
t_stockap		g_pac;
t_keymaster		g_lock;

int				ft_inienv(t_masterenv *menv, char **env);
void			ft_inirep(t_masterenv *menv, int option);
void			ft_controlcer(int signo);
int				ft_bufdissek(t_masterenv *menv, char *buf);
int				ft_echo(t_masterenv *menv, char **opt);
int				ft_cd(t_masterenv *menv, char **opt);
int				is_dir(char *name);
int				is_file(char *name);
int				is_truedir(char *test);
int				ft_getbuf(char **buf);
int				ft_retoucheur(char **toretouch, t_masterenv *menv);
int				ft_classor(t_masterenv *menv, char **buf);
int				ft_calculator(char **toretouch, t_masterenv *menv);
void			ft_nospace(char **despacito);
int				ft_nbopnbrs(char **calc, t_calctools *stock, int k, int i);
int				ft_stockremplissor(char **calc, t_calctools *stock, int k);
int				ft_inistuff(t_calctools *stock);
int				ft_elcalc(t_calctools *stock);
int				ft_setenv(t_masterenv *menv, char **opt);
int				ft_unsetenv(t_masterenv *menv, char **opt);
int				ft_pathfinder(t_masterenv *menv, t_masterenv *tenv);
int				ft_trouverror(char **calc);
void			ft_freear(t_masterenv *menv, char *buf);
int				ft_setenvcgc3xistpo(t_masterenv *menv, int i, char **tenv,
char **opt);
int				ft_setenvcgc3xist(t_masterenv *menv, int i, char **opt);
int				ft_setenvcgc2xistpo(t_masterenv *menv, int i, char **opt);
int				ft_setenvcgc2xist(t_masterenv *menv, int i);
int				ft_findfct(t_masterenv *menv, char **tmp, char *cmd);
int				ft_cdchecker(char **tmp);
int				ft_cdgcequal1(t_masterenv *menv, char **tmp);
int				ft_getit(char **toretouch, int i, t_masterenv *menv);
int				ft_remplissor(t_masterenv *menv, int nb, char *buf);
int				ft_elcalcpower(int i, t_calctools *stock);
void			ft_instuff1(t_trouvtrouss *troux);
void			ft_instuff2(t_trouvtrouss *troux);
int				ft_elser(char **calc, int i, int j);
void			ft_microini(int *i, int *j, t_trouvtrouss *troux);
int				ft_trouvewhilebegin(char **calc, int *i, int *j);
int				ft_trouvecore(t_trouvtrouss *troux, int *i, char **calc,
	int j);
void			ft_trunkator(t_calctools *stock, int i);
int				ft_trouverrorbegin(char **calc);
int				ft_answ(t_calctools *stock);
int				ft_resultor(char **calc);
int				ft_unfinishedollar(int *cpt, int *i);
int				ft_addnewline(char **buf);
int				ft_cdgcsup(t_masterenv *menv, char **tmp, char **pwd,
char **opt);
int				ft_getopt(char **opt, t_masterenv *menv);
void			ft_printnewpwd(t_masterenv *menv, char **tmp);
int				ft_unsetenver(t_masterenv *menv, int i, char **tenv, int k);
int				ft_setenvcgc3(t_masterenv *menv, char **opt);
int				ft_protoc(char **buf, t_masterenv *menv, t_keymaster *lock);
void			ft_findfctscript(char **tmp);

int				ft_cannoner(void);
void			ft_termoder(int mode);

int				ft_unfinished(t_stockap *pac, t_keymaster *lock,
t_masterenv *menv);
int				ft_ultilooperbeginner(t_stockap *pac, t_keymaster *lock,
	t_masterenv *menv);
int				ft_typer(t_masterenv *menv, char **opt);
int				ft_pipe_exec(int i, t_masterenv *menv);
int				ft_builtin(t_masterenv *tenv, char **opt);
int				ft_findpathperm(t_masterenv *menv, char **cmd, char *tmp);
int				ft_checkpipe(t_masterenv *menv, int i);
int				ft_getnextpipe(t_masterenv *menv, int ind);
int				ft_addtohist(char *ultib, t_keymaster *lock);
int				okforhist(void);
int				is_event(char **cmd, int pos);
int				ft_create_hist(t_keymaster *lock);
void			ft_gethistfile(t_keymaster *lock, t_masterenv *menv);
int				ft_read_hist(char **str, t_keymaster *lock, int fd_file);
int				hist_reader(char *buf, int fd_file, char **str, int b);
int				ft_uphist(t_keymaster *lock, t_stockap *pac);
int				ft_downhist(t_keymaster *lock, t_stockap *pac);
void			ft_freetabc(char **cmd);
int				exp_main(char **cmd, t_keymaster *lock);
int				ft_expensions(char **cmd, t_keymaster *lock);
int				no_event(char **cmd, int i);
int				theresexp(char *str, t_keymaster *lock);
void			changexp(char **cmd, char *tmp, int d[2], t_keymaster *lock);
void			ft_replace(char **old, char *new);
void			ft_replace_cmd(char **old, char *new);
char			*ft_histpath(char *path, char *histdoc);
char			*getshlvl(t_masterenv *menv);

int				ft_checkredir(t_masterenv *menv, int start, int end);
void			ft_redir_exec(t_masterenv *menv, int k);
void			ft_executor_pipe(int start, int end,
t_masterenv *menv);
int				ft_agreg(t_masterenv *tenv, int j, int *fd_agregin, int *fd_b);
int				ft_redir(t_masterenv *menv);
void			ft_dup(int *fdd, int *pipefd, int fd);
int				ft_agreg(t_masterenv *tenv, int j, int *fd_agregin, int *fd_b);
int				ft_checkredirout(t_masterenv *menv, int a);
int				ft_checkredirerror(t_masterenv *tenv, int i, int fd_agregin);
int				ft_redirout(t_masterenv *tenv, int j, int fd_agregin);
int				ft_checkredirinfile(t_masterenv *menv, int i);
int				ft_redirin(t_masterenv *tenv, int i);
int				ft_checkagreg(t_masterenv *menv, int a);
int				ft_strstri(char *haystack, char *needle);
int				ft_checkredirfd(char *str);
int				ft_checkfd(char *str);
int				ft_restablish(int fd_b, int fd_agregin);
int				ft_recupfd(t_masterenv *menv, int j);
int				ft_checkfderror(int fd);
int				ft_checkredirin(t_masterenv *menv, int a);
int				ft_checkperm(t_masterenv *menv, int i, int type);
char			*ft_getheredoc(void);

int				ft_addcara(t_keymaster *lock, t_stockap *pac);
int				ft_activkey(t_keymaster *lock, t_stockap *pac,
t_masterenv *menv);
void			ft_delcaracursor(t_keymaster *lock, t_stockap *pac);
int				ft_delcara(t_keymaster *lock, t_stockap *pac);
void			ft_addcaracursor(t_keymaster *lock, t_stockap *pac);
void			ft_putatend(t_keymaster *lock, t_stockap *pac);
void			ft_goright(t_keymaster *lock, t_stockap *pac);
void			ft_simplegoright(t_keymaster *lock, t_stockap *pac);
int				ft_getkey(char *buf, t_keymaster *lock);
void			ft_goleft(t_keymaster *lock, t_stockap *pac);
void			ft_seeyoulater(t_masterenv *menv, t_keymaster *lock);
int				ft_ultimain(t_masterenv *menv, t_keymaster *lock);
int				ft_unfinishedcore(int i, int cpt, t_keymaster *lock);

int				ft_masterprompt(t_keymaster *lock);
int				ft_dquoteprompt(t_keymaster *lock);
int				ft_quoteprompt(t_keymaster *lock);
int				ft_mathprompt(t_keymaster *lock);
int				ft_mathquoteprompt(t_keymaster *lock);
int				ft_mathdquoteprompt(t_keymaster *lock);
int				ft_simpleprompt(t_keymaster *lock);
int				ft_searchprompt(t_keymaster *lock);

int				ft_pathslasher(t_masterenv *menv, int *unknown);
int				ft_errorprompt(t_keymaster *lock);

void			ft_gobigleft(t_keymaster *lock, t_stockap *pac);
void			ft_gobigright(t_keymaster *lock, t_stockap *pac);
int				ft_autok(t_keymaster *lock, t_stockap *pac, t_masterenv *menv);

void			ft_basicmainloop(t_stock *stock, t_stockap *pac,
	t_basiks *tools, t_ijer *lol);
int				ft_basic(t_stock *stock, t_stockap *pac, t_basiks *tools,
	t_keymaster *lock);
void			ft_simpleputatend(t_keymaster *lock, t_stockap *pac);
int				ft_fctsremplissor(t_masterenv *menv);
int				ft_refcts(t_masterenv *menv);
int				ft_outputfiller(t_keymaster *lock);
int				ft_addcompletion(t_keymaster *lock, t_stockap *pac);
int				ft_commander(t_keymaster *lock, t_stockap *pac);
int				ft_pathter(t_keymaster *lock, t_stockap *pac, int mode);
int				ft_pather(t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv);
int				ft_pather_end(t_keymaster *lock, t_stockap *pac, int i);
int				ft_pather_1opt_dir(t_keymaster *lock, int i);
int				ft_pather_1opt_file(t_keymaster *lock, int i);
int				ft_pathter_pathchoice(t_keymaster *lock, t_stockap *pac,
	int i);
int				ft_pathter_commandchoice(t_keymaster *lock, t_stockap *pac,
	int i);
int				ft_pathter_pathchoice_dir(t_keymaster *lock);
int				ft_pathter_pathchoice_file(t_keymaster *lock);
int				ft_autoker(t_keymaster *lock, t_stockap *pac, int mode
	, t_masterenv *menv);
int				ft_basic_end(t_stock *stock, t_stockap *pac, t_basiks *tools);
void			ft_reboot(t_stock *stock);
int				ft_basicimpossible(t_stock *stock, t_basiks *tools);
void			ft_putatbegin(t_keymaster *lock, t_stockap *pac);
int				ft_switchout(t_keymaster *lock, t_stockap *pac
	, char *toswitch);
int				ft_autokerbis(t_keymaster *lock, t_stockap *pac, int mode
	, t_masterenv *menv);
int				ft_pars_mk2(t_masterenv *menv, char **buf);
int				ft_pars_mk2_helper(t_masterenv *menv, int i, char **buf);
int				ft_ultimain_mk2(char **buf);
void			ft_quoters(int *quoters, int yep);
int				ft_notbltin(char *test);
int				ft_prelauncher(char **buf, t_masterenv *menv,
	t_keymaster *lock);
int				ft_checkcreate(t_masterenv *menv);
int				ft_printfhisto(t_keymaster *lock);
int				ft_cutprompt(t_keymaster *lock);
int				ft_cpyprompt(t_keymaster *lock);
void			ft_refreash(t_keymaster *lock, t_stockap *pac);
int				ft_bufselecter(t_keymaster *lock, t_stockap *pac);
int				ft_iscommand(t_keymaster *lock);
int				ft_hereprompt(t_keymaster *lock);
int				ft_newread(t_keymaster *lock, t_stockap *pac,
	t_masterenv *menv);
int				ft_bufator(char **buf, char *sbuff);
int				ft_hereshlag(t_stockap *pac, t_keymaster *lock,
	t_masterenv *menv);
int				ft_unfinishedlauncher(t_stockap *pac, t_keymaster *lock,
	t_masterenv *menv);
int				ft_newgetbuf(char **buf, t_keymaster *lock, t_stockap *pac,
	t_masterenv *menv);
int				ft_lastprompt(t_keymaster *lock);
int				ft_ctrlder(t_keymaster *lock, t_stockap *pac,
	t_masterenv *menv);
char			*ft_fakedbs(char	*str);
int				put_bsbsn(int c, char **tmp);
void			ft_multicator(t_masterenv *menv, int rekool);
int				ft_cgtrier(t_masterenv *menv, int j, int k);
int				ft_cgepurator(t_masterenv *menv);
int				ft_prio(t_masterenv *menv, char **buf);
int				ft_if_prio(t_masterenv *menv, int i, int nope, char **buf);
int				ft_errorpars_mk2(t_masterenv *menv, char **buf);
int				ft_findparserror(char *check);
int				ft_findparserror_v2(t_masterenv *menv, char **buf);
int				ft_seter(int *i, char **buf, char multi);
int				seter_if(int *i, int *j, char **buf, char multi);
int				seter_following(int *i, int *j, char **buf,
	char multishlag[10]);
void			ft_triploswitch(t_masterenv *menv, int a, int b);
void			ft_memtmp(t_tmper *tmp1, t_tmper *tmp2, t_masterenv *menv,
	int i);
void			ft_resmemtmp(t_tmper *tmp1, t_tmper *tmp2, t_masterenv *menv,
	int i);
void			ft_tab3decaler(t_masterenv *menv, int looker, int rekool);
int				hist_quotes(void);
int				ft_maxfinder_ender(t_basiks *tools, struct winsize w);
int				ft_herror(t_keymaster *lock);
int				ft_pathfilemaker(t_keymaster *lock, t_masterenv *menv);
int				ft_savepresspap(t_keymaster *lock, t_stockap *pac);
void			ft_pather_free(t_keymaster *lock);
int				ft_failed(void);
void			ft_right(t_keymaster *lock, t_stockap *pac);
void			ft_inicap(t_stockap *pac);
int				init_term(void);
char			*ft_inirep_pt2(int option, t_masterenv *menv, char *save);
void			ft_stock(t_masterenv *menv, int i);
int				ft_cd2op_pt2(t_masterenv *menv, char *tmp);
int				ft_checktmp(char **tmp, t_masterenv *menv, char **opt, int i);
int				ft_is_logical(char *pwd, char **tmp, t_masterenv *menv
	, char **opt);
void			ft_microcd(char **tmp);
void			ft_seeyoulater_bitch(t_masterenv *menv, t_keymaster *lock);
int				ft_trouverrornozero(char **calc, int i, int nomore
	, int nozero);
int				ft_trouverrorwarning(char **calc, int i, int nomore);
int				ft_pather_pakoul(t_keymaster *lock);

/*
** Dollar expansion
*/
char			*cmp_getvalue(char *env, char *name);
char			*get_var(t_masterenv *menv, char *var, int i);
char			*sharp_exp(t_masterenv *menv, char *var, int pos);
char			*percent_exp(t_masterenv *menv, char *var, int pos);
int				colon_exp(t_masterenv *menv, char *var, int pos
	, char **final_form);
int				ft_substitution(t_masterenv *menv, char *var
	, char **final_form);
int				ft_dollar_expansion(t_masterenv *menv, char **cmd);
int				len_cmd(char **cmd, char *final_form);
int				ft_check_error(char *var);
int				increment_k(int l, int k);
int				do_recursiv(t_masterenv *menv, char **cmd, char *var);
int				change_cmd(char **cmd, char *final_form);
int				one_dollar_exp(t_masterenv *menv, char **cmd);
int				free_norme(char **str, char **sstr, int ret);
int				check_digit(char *var);
int				ft_add_to_intern_var(t_masterenv *menv, int i);

char			*get_value_simple_dollar(t_masterenv *menv, char *name);
int				do_digit_dollar(char **cmd, int	start);
int				ft_simple_dollar(t_masterenv *menv, char **cmd);

/*
** Intern var
*/
char			*ft_findvar(char *intern_var, char *name);
char			**ft_reset_tab(char **old_tab, int resize);
int				ft_init_internalvar(t_masterenv *menv);
int				ft_unset(char ***internal_var, char **name, int ret);
char			*setvar(char *name, char *value);
void			ft_addvar(char ***tab_var, char *cmd);
int				ft_set(char **internal_var);
int				ft_export(t_masterenv *menv, char **opt);
int				check_error_flag(char *opt);
int				check_error_arg(char *opt);
void			print_error(int ret, char *opt);
int				ft_checkintvar(char *lol);
void			ft_tabfree(char **free_tab);

int				ft_dofc(t_masterenv *menv, t_keymaster *lock, char **cmd);
char			**pre_simple(char **cmd);
char			*simple_fc(t_masterenv *menv, t_keymaster *lock, char **cmd
	, char *exec);
int				fc_noarg(t_masterenv *menv, t_keymaster *lock
	, t_masterenv *tenv, char *exec);
char			*replacebsn(char *str);

void			fc_list(t_keymaster *lock, int opt, char **cmd);
void			fc_rlist(t_keymaster *lock, int opt, char **cmd);
char			*fc_s(t_keymaster *lock, int i, char **cmd);
char			*fc_editor(t_masterenv *menv, t_keymaster *lock, char **cmd);
char			*fc_editor_spe(t_masterenv *menv, t_keymaster *lock);
char			*fc_editor_simple(t_masterenv *menv, t_keymaster *lock
	, char *cmd, int tofree);
char			*r_edit_exec(t_masterenv *menv, t_keymaster *lock
	, int i[2], char *edit);
char			*fc_editor_reader(char *exec, int fd);
int				ft_exec_fc(char *exec, t_masterenv *menv, t_masterenv *tenv
	, t_keymaster *lock);
int				ft_strdigit(char *str);
int				ft_stralpha(char *str);
char			*fc_chr(t_keymaster *lock, int i, char **cmd);
void			error_list();
int				is_fcfile_ok();
int				options(char *str);
int				illegal_opt(char c);
void			fc_usage();

int				add_alias(t_masterenv *menv, char **opt);
void			replace_alias(char **cmd, t_masterenv *menv);
void			end_replace(char **cmd, char *bef, char *alsed, char *aft);
int				last_space(char *str);
int				is_apb(char	c);
int				nothing_next(char *str, int i);
int				can_we_alias(char *str, int deb, int fin);
int				ft_strpos(char *haystack, char *needle, int start);
char			*cycle_alias(char *first, char *str, t_alias *als);
int				unalias(t_masterenv **tenv, char **del);
t_alias			*ft_create_lst(char *alias, char *name);
void			ft_lst_push_back(t_alias **als, char *alias, char *name);
void			ft_lst_show(t_alias *als);
int				ft_lst_clear(t_alias **als);
int				ft_jobs(t_masterenv *menv, char **opt);
int				ft_bg(t_masterenv *menv, char **opt);
int				ft_fg(t_masterenv *menv, char **opt);
int				ft_execute_bg(t_keymaster *lock, t_masterenv *menv);
int				ft_histsearch(t_keymaster *lock, t_stockap *pac
	, t_masterenv *menv);
int				ft_newreadstuff(t_keymaster *lock, t_stockap *pac, int option);

/*
** Signaux
*/
void			ft_init_signals(void);
void			ft_reset_signals(void);
void			ft_quit_on_signal(int sig);
void			ft_signal_handler(int sig);

/*
** job control
*/
char			**ft_arraydup(char **array);
int				ft_init_jobctrl(void);
void			go_foreground(t_job *job, int cont);
int				launch_job(int foreground, char *path, t_masterenv *menv
	, char **opt);
t_job			*get_joblist(t_job *new_j);
int				job_stopped(t_job *job);
int				job_completed(t_job *job);
int				set_status_job(pid_t pid, int status);
int				in_the_list(t_job *job);
void			todo_on_sigchld(void);
void			free_job(t_job *job);
void			update_jobs(void);
t_process		*new_process(void);
void			set_process(t_job *job, int pid, int start, t_masterenv *menv);
t_job			*new_job(void);
void			go_background(t_masterenv *menv, t_job *job, int cont);
int				ft_exiter(t_masterenv *menv, char **opt, t_keymaster *lock);
void			back_fore(t_masterenv *menv, t_job *job, int fg);
int				error_job(t_job *job, char *str);
void			process_info(t_masterenv *menv, t_job *job, pid_t pid
	, int start);
void			print_in_while_jobser(t_job *job, int flag, int ambiguous);
void			print_job(t_job *job);
void			print_job_l(t_job *job);
void			back_fore_norme(t_masterenv *menv, t_job *job);
int				while_jobser(char **opt, int *f, int *i_opt);

void			focus_minus(t_job *job);
void			check_plus(void);
void			plus_minus(void);
t_job			*get_job_with_nb(char *arg);
t_job			*get_job_with_str(char *arg, int *ambiguous);
t_job			*get_current_job(void);
t_job			*get_previous_job(void);
t_job			*search_job(char *arg, int *ambiguous);
void			launch_process(t_job *job, t_masterenv *tenv, int fg);
int				ft_goodcara(char **calc);
int				ft_ulticalc(char **calc, t_masterenv *menv);
int				ft_ulticalclauncher(char **calc, t_masterenv *menv);
int				ft_calcomparator(char **calc, int i);
int				ft_checkcalc(char **calc);
void			print_status(t_job *job, char *status);
void			wait_job(t_job *job);
void			serial_killer(void);
int				ft_check_agregin(t_masterenv *tenv, int j);
t_job			*ft_init_redir(int *fd_agregin, int *fd_b, t_masterenv *menv);
int				ft_init_pipe(int *start, int *i, int *fdd, t_masterenv *tenv);
int				ft_fork_parent(t_job *new_j, t_masterenv *menv, int nb);
int				ft_pipe_error(t_job *cur_j, int *i, int *pipefd, int k);
void			ft_close_pipe(int *pipefd);
int				ft_get_next(int *start, int *ind, t_masterenv *tenv);
int				ft_process_pipe(t_masterenv *tenv, t_job *cur_j, int start
	, int *pipefd);
void			ft_mutant_refreash(int lenth, t_stockap *pac);
int				ft_search(t_keymaster *lock);
int				ft_activkey_2(t_keymaster *lock, t_stockap *pac);
int				ft_check_exit(t_masterenv *tenv);
int				ft_exitn(char *opt, t_masterenv *menv);
int				ft_exec_simple(t_masterenv *menv, char **opt);
int				ft_tester(t_masterenv *tenv, char **opt);
int				ft_check_opt1(char *opt);
int				ft_check_opt2(char *opt);
int				ft_unary_test(t_masterenv *tenv, int size, char **opt
	, int op);
int				ft_binary_test(t_masterenv *tenv, int size, char **opt
	, int op);
int				ft_testb(t_masterenv *tenv, char *opt);
int				ft_testc(t_masterenv *tenv, char *opt);
int				ft_testd(t_masterenv *tenv, char *opt);
int				ft_teste(t_masterenv *tenv, char *opt);
int				ft_testf(t_masterenv *tenv, char *opt);
int				ft_testg(t_masterenv *tenv, char *opt);
int				ft_testl(t_masterenv *tenv, char *opt);
int				ft_testp(t_masterenv *tenv, char *opt);
int				ft_testr(t_masterenv *tenv, char *opt);
int				ft_test_s(t_masterenv *tenv, char *opt);
int				ft_tests(t_masterenv *tenv, char *opt);
int				ft_testu(t_masterenv *tenv, char *opt);
int				ft_testw(t_masterenv *tenv, char *opt);
int				ft_testx(t_masterenv *tenv, char *opt);
int				ft_testz(t_masterenv *tenv, char *opt);
int				ft_test_eq(t_masterenv *tenv, char *str1, char *str2);
int				ft_test_ne(t_masterenv *tenv, char *str1, char *str2);
int				ft_test_ge(t_masterenv *tenv, char *str1, char *str2);
int				ft_test_gt(t_masterenv *tenv, char *str1, char *str2);
int				ft_test_lt(t_masterenv *tenv, char *str1, char *str2);
int				ft_test_le(t_masterenv *tenv, char *str1, char *str2);
int				ft_error_integer(long long int *nb, char *str);
char			*ft_getvalue(t_masterenv *menv, char *name);
void			ft_supvar(t_masterenv *tenv, int start);
int				ft_checkcdpath(char **pwd, t_masterenv *menv, char **opt
	, int i);
char			*browse_tab(char **tab_var, char *name);
int				ft_inenvremplissor(t_masterenv *menv);
int				ft_cmd_size(t_job *job, char **tmp);
void			ft_print_pipe(t_process *process);
int				ft_switcher(char **toretouch, int i, t_masterenv *menv);
int				ft_pather_pt1(t_keymaster *lock, t_masterenv *menv);
int				ft_inenver(t_keymaster *lock, t_stockap *pac);
int				ft_pathter_inenvchoice(t_keymaster *lock, t_stockap *pac
	, int i);
void			ft_unomemtmp(t_tmper *tmp1, t_masterenv *menv, int i);
void			ft_unoresmemtmp(t_tmper *tmp1, t_masterenv *menv, int i);
void			ft_unotab3decaler(t_masterenv *menv, int rekool, int looker);
void			ft_getridofintvar(t_masterenv *menv, int i);
int				ft_is(char *lol);
int				ft_remplissorpt1calchelper(int i, char *buf, char par);
int				ft_corecalcomparator_badend(char **avant);
int				ft_elcalcender(t_calctools *stock, int i);
int				ft_worder(char **word);
void			ft_incbef(char *word, char **number, int incbef
	, t_masterenv *menv);
void			ft_incaft(char *word, char **number, int incaft
	, t_masterenv *menv);
int				ft_changend(t_masterenv *menv, char **calc, int i);
int				ft_createwn_pt2(char **word, char **number, char **calc
	, int i);
void			ft_putanswer(char **string, double *number);
int				ft_lifechecker(char *totest);
void			freepreulticalc(char ***tablor, double **ftabor
	, int **indexor);
int				ft_gettoit(double **ftabor, int **indexor, char ***tablor);
int				ft_preulticalcmallocer(char **calc, t_preult *eul);
int				ft_preulticalcremplissor(char **calc, t_preult *eul);
int				freethatshit(t_masterenv *menv, int j, char *buf);
int				ft_destroy_mk2_core_noquote(char **dest, t_masterenv *menv
	, int i);
int				ft_destroy_mk2_core_quote(char **dest, t_masterenv *menv
	, t_nbtool *koul, int i);
int				ft_preultimain_mk2(char **ultib, t_masterenv *menv
	, t_keymaster *lock);
int				findparserror(char **ultib);
char			*ft_opt_cmd(int k, int i, t_masterenv *menv);
char			*ft_opt_pipe(int k, int i, t_masterenv *menv, int end);
int				ft_fcinfc(char *exec);
int				ft_exec_builtin_redir(t_masterenv *menv);
int				ft_check(t_masterenv *tenv, int *fd_agregin, int *fd_b);
int				ft_savefdb(int *fd);
char			*ft_getvalue_cd(t_masterenv *menv, char *name);
int				ft_supvarinit(t_masterenv *tenv, int start);
char			**ft_supvarcre(t_masterenv *tenv, int size, int i, int j);
int				ft_cinquantequatre(t_keymaster *lock, t_stockap *pac);
int				ft_newreadcore_2(t_keymaster *lock, t_stockap *pac);
void			ft_controlcerstuff_2(void);
int				ft_badending(char **ultib, int opt);
int				ft_preultimain_mk2_core1_altend(char **ultib, t_masterenv *menv
	, int i);
void			ft_init_preucore1(char **ultib, t_masterenv *menv, int i);
int				ft_preultimain_mk2_core1(char **ultib, t_masterenv *menv
	, t_keymaster *lock, int i);
int				ft_preultimain_mk2_core2(char **ultib, t_masterenv *menv
	, t_keymaster *lock);
int				ft_preultimain_mk2_pt2(char **ultib, t_masterenv *menv
	, t_keymaster *lock);
int				ft_preultimain_mk2_i(char **ultib, int i);
int				findparserror_core(char **ultib, int i);
void			ft_stock2(t_masterenv *menv);
char			*ft_strjoinhist(char *s1, char *s2);
char			*ft_strduphist(char *buf);
int				ft_braceprompt(t_keymaster *lock);
int				ft_unfinishedcore_pt2(int i, int cpt, t_keymaster *lock);
int				ft_openhist(t_keymaster *lock);
int				ft_cdpathchecker(char *tmp);
int				jpp(t_keymaster *lock);
int				ft_check_final(t_masterenv *menv, char **buf);
int				ft_pathfinal(t_masterenv *menv, char **cmd, char *tmp, int *nf);
int				ft_piperror(t_masterenv *menv, char **buf);
#endif
