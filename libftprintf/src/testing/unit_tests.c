/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:15:57 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/07 22:43:25 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*
** Add unit tests to this file. Return 1 if fail, 0 if pass.
**
** All functions of the prototype:
**
**     int    foo(void)
**
** will be considered a unit test.
*/

//Tests with no specifiers
int		no_specifier_test(void){return test("hello, world!");}
int		empty_string(void){return test("");}
int		some_escaped_chars(void){return test("\t\n\r\v\f\n");}

//String specifiers - no modifiers
int		basic_string_expansion(void){return test("hello, %s.", "gavin");}
int		only_string_expansion(void){return test("%s", "testing testing");}
int		two_string_expansions(void){return test("%s%s", "hello", "world");}
int		two_string_expansions2(void){return test("..%s stuff %s", "a", "b");}
int		empty_string_expansion(void){return test("this %s is empty", "");}
int		full_then_empty_string(void){return test("this %s is %s", "hello", "");}
int		empty_then_full_string(void){return test("this %s is %s", "", "hello");}
int		three_strings(void){return test("%s%s%s", "1", "2", "3's a charm");}
//String specifiers with field_width, space- or zero-padded
int		space_padded_field_width(void){return test("%32s", "abc");}
int		space_padded_field_width2(void){return test("%16s", "nark nark");}
int		space_padded_over_field_width(void){return test("%5s", "goes over");}
int		zero_padded_field_width(void){return test("%021s", "abc");}
int		zero_padded_over_field_width(void){return test("%05s", "goes over");}
//String specifiers with field_width, space- or zero-padded, left-justified
int		space_padded_field_width_lj(void){return test("%-32s", "abc");}
int		space_padded_field_width2_lj(void){return test("%-16s", "nark nark");}
int		space_padded_over_field_width_lj(void){return test("%-5s", "goes over");}
int		zero_padded_field_width_lj(void){return test("%-021s", "abc");}
int		zero_padded_over_field_width_lj(void){return test("%-05s", "goes over");}
//String specifiers with precision
int		string_prec_notrunc(void){return test("%.7s", "hello");}
int		string_prec_trunc(void){return test("%.3s", "hello");}
int		string_prec_default(void){return test("%.s", "hello");}
int		string_prec_zero(void){return test("%.0s", "hello");}
int		two_strings_prec_2trunc(void){return test("%.3s%.2s", "holla", "bitch");}
int		two_strings_prec_1trunc_a(void){return test("%.2s%.7s", "hello", "world");}
int		two_strings_prec_1trunc_b(void){return test("%.7s%.2s", "hello", "world");}
int		two_strings_prec_0trunc(void){return test("%.5s%7s", "yo", "boi");}
//String specifiers with both precision and field width
int		string_prec_width_notrunc(void){return test("%7.5s", "yolo");}
int		string_prec_width_trunc(void){return test("%7.5s", "bombastic");}
int		string_prec_width_notrunc_lj(void){return test("%-7.5s", "yolo");}
int		string_prec_width_trunc_lj(void){return test("%-7.5s", "tubular");}
int		two_str_prec_width_2fit_0trunc(void){return test("%7.7s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_a_0trunc(void){return test("%3.7s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_b_0trunc(void){return test("%7.7s%3.7s", "hello", "world");}
int		two_str_prec_width_0fit_0trunc(void){return test("%3.7s%3.7s", "hello", "world");}
int		two_str_prec_width_2fit_1trunc_a(void){return test("%7.3s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_a_1trunc_a(void){return test("%3.3s%7.7s", "hello", "world");}
int		two_str_prec_width_1fit_b_1trunc_a(void){return test("%7.3s%3.7s", "hello", "world");}
int		two_str_prec_width_0fit_1trunc_a(void){return test("%3.3s%3.7s", "hello", "world");}
int		two_str_prec_width_2fit_1trunc_b(void){return test("%7.7s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_a_1trunc_b(void){return test("%3.7s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_b_1trunc_b(void){return test("%7.7s%3.3s", "hello", "world");}
int		two_str_prec_width_0fit_1trunc_b(void){return test("%3.7s%3.3s", "hello", "world");}
int		two_str_prec_width_2fit_2trunc(void){return test("%7.3s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_a_2trunc(void){return test("%3.3s%7.3s", "hello", "world");}
int		two_str_prec_width_1fit_b_2trunc(void){return test("%7.3s%3.3s", "hello", "world");}
int		two_str_prec_width_0fit_2trunc(void){return test("%3.3s%3.3s", "hello", "world");}
int		two_str_prec_width_2trunc(void){return test("%3s%3s", "hello", "world");}
//String specifiers, other tests
int		two_strings_lj_and_rj(void){return test("%-7s%5s", "hello", "world");}
int		two_strings_rj_and_lj(void){return test("%7s%-5s", "hello", "world");}
int		two_strings_zrjtrunc_and_ljtrunc(void){return test("%04.3s%-7.4s", "hello", "world");}

//Signed integers - no modifers
int		basic_sint_pos(void){return test("this %i number", 17);}
int		basic_sint_neg(void){return test("this %i number", -267);}
int		basic_sint_zero(void){return test("this %i number", 0);}
int		basic_sint_onlypos(void){return test("%i", 3);}
int		basic_sint_onlyneg(void){return test("%i", -1);}
int		basic_sint_onlyzero(void){return test("%i", 0);}
int		basic_sint_pos_d(void){return test("this %d number", 17);}
int		basic_sint_neg_d(void){return test("this %d number", -267);}
int		basic_sint_zero_d(void){return test("this %d number", 0);}
int		sint_intmax(void){return test("%i", 2147483647);}
int		sint_intmin(void){return test("%i", -2147483678);}
//Signed integers with allsign ('+')
int		sint_allsign_pos(void){return test("%+i", 5);}
int		sint_allsign_neg(void){return test("%+i", -7);}
int		sint_intmax_allsign(void){return test("%+i", 2147483647);}
//Signed integers with field width
int		sint_width_pos_fits(void){return test("%7i", 33);}
int		sint_width_neg_fits(void){return test("%7i", -14);}
int		sint_width_zero_fits(void){return test("%3i", 0);}
int		sint_width_pos_exactfit(void){return test("%5i", 52625);}
int		sint_width_neg_exactfit(void){return test("%5i", -2562);}
int		sint_width_pos_nofit(void){return test("%4i", 94827);}
int		sint_width_neg_nofit(void){return test("%4i", -2464);}
int		sint_width_pos_fits_lj(void){return test("%-7i", 33);}
int		sint_width_neg_fits_lj(void){return test("%-7i", -14);}
int		sint_width_zero_fits_lj(void){return test("%-3i", 0);}
int		sint_width_pos_exactfit_lj(void){return test("%-5i", 52625);}
int		sint_width_neg_exactfit_lj(void){return test("%-5i", -2562);}
int		sint_width_pos_nofit_lj(void){return test("%-4i", 94827);}
int		sint_width_neg_nofit_lj(void){return test("%-4i", -2464);}
//signed integers with field width and allsign
int		sint_width_allsign_pos(void){return test("%+5i", 35);}
int		sint_width_allsign_zero(void){return test("%+7i", 0);}
int		sint_width_intmax_allsign(void){return test("%+24i", 2147483647);}
//signed integers with precision
int		sint_prec_fits_pos(void){return test("%.5i", 2);}
int		sint_prec_fits_neg(void){return test("%.6i", -3);}
int		sint_prec_fits_zero(void){return test("%.3i", 0);}
int		sint_prec_exactfit_pos(void){return test("%.4i", 5263);}
int		sint_prec_exactfit_neg(void){return test("%.4i", -2372);}
int		sint_prec_nofit_pos(void){return test("%.3i", 13862);}
int		sint_prec_nofit_neg(void){return test("%.3i",-23646);}
int		sint_prec_allsign_pos(void){return test("%+.7i", 234);}
int		sint_prec_allsign_neg(void){return test("%+.7i", -446);}
int		sint_prec_allsign_pos_nofit(void){return test("%+.3i", 3723);}
//Signed integers with zero field width padding
int		sint_zpad_pos_fits(void){return test("%05i", 43);}
int		sint_zpad_neg_fits(void){return test("%07i", -54);}
int		sint_zpad_zero_fits(void){return test("%03i", 0);}
int		sint_zpad_pos_exactfit(void){return test("%03i", 634);}
int		sint_zpad_neg_exactfit(void){return test("%04i", -532);}
int		sint_zpad_neg_minus1fit(void){return test("%04i", -4825);}
int		sint_zpad_allsign_fits(void){return test("%+05i", 432);}
int		sint_zpad_allsign_zero(void){return test("%+04i", 0);}
//Signed integers with field width and precision
int		sint_prec_width_fit_fit_pos(void){return test("%8.5i", 34);}
int		sint_prec_width_fit_fit_neg(void){return test("%10.5i", -216);}
int		sint_prec_width_fit_fit_zero(void){return test("%8.5i", 0);}
int		sint_prec_width_nofit_fit_pos(void){return test("%8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg(void){return test("%8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos(void){return test("%3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg(void){return test("%3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos(void){return test("%3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg(void){return test("%3.3i", -8462);}
//Signed integers with field width and precision, left-justified
int		sint_prec_width_fit_fit_pos_lj(void){return test("%-8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj(void){return test("%-10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj(void){return test("%-8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj(void){return test("%-8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj(void){return test("%-8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj(void){return test("%-3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj(void){return test("%-3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj(void){return test("%-3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj(void){return test("%-3.3i", -8462);}
//Signed integers with field width and precision with allsign
int		sint_prec_width_fit_fit_pos_allsign(void){return test("%+8.5i", 34);}
int		sint_prec_width_fit_fit_neg_allsign(void){return test("%+10.5i", -216);}
int		sint_prec_width_fit_fit_zero_allsign(void){return test("%+8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_allsign(void){return test("%+8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_allsign(void){return test("%+8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_allsign(void){return test("%+3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_allsign(void){return test("%+3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_allsign(void){return test("%+3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_allsign(void){return test("%+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign
int		sint_prec_width_fit_fit_pos_lj_allsign(void){return test("%+-8.5i", 34);}
int		sint_prec_width_fit_fit_neg_lj_allsign(void){return test("%+-10.5i", -216);}
int		sint_prec_width_fit_fit_zero_lj_allsign(void){return test("%+-8.5i", 0);}
int		sint_prec_width_nofit_fit_pos_lj_allsign(void){return test("%+-8.3i", 8375);}
int		sint_prec_width_nofit_fit_neg_lj_allsign(void){return test("%+-8.3i", -8473);}
int		sint_prec_width_fit_nofit_pos_lj_allsign(void){return test("%+-3.7i", 3267);}
int		sint_prec_width_fit_nofit_neg_lj_allsign(void){return test("%+-3.7i", -2375);}
int		sint_prec_width_nofit_nofit_pos_lj_allsign(void){return test("%+-3.3i", 6983);}
int		sint_prec_width_nofit_nofit_neg_lj_allsign(void){return test("%+-3.3i", -8462);}
//Signed integers with field width and precision with zeropadding
int		sint_prec_width_ff_pos_zpad(void){return test("%08.5i", 34);}
int		sint_prec_width_ff_neg_zpad(void){return test("%010.5i", -216);}
int		sint_prec_width_ff_zero_zpad(void){return test("%08.5i", 0);}
int		sint_prec_width_nf_pos_zpad(void){return test("%08.3i", 8375);}
int		sint_prec_width_nf_neg_zpad(void){return test("%08.3i", -8473);}
int		sint_prec_width_fn_pos_zpad(void){return test("%03.7i", 3267);}
int		sint_prec_width_fn_neg_zpad(void){return test("%03.7i", -2375);}
int		sint_prec_width_nn_pos_zpad(void){return test("%03.3i", 6983);}
int		sint_prec_width_nn_neg_zpad(void){return test("%03.3i", -8462);}
//Signed integers with field width and precision, left-justified with zeropadding
int		sint_prec_width_ff_pos_lj_zpad(void){return test("%0-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_zpad(void){return test("%0-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_zpad(void){return test("%0-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_zpad(void){return test("%0-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_zpad(void){return test("%0-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_zpad(void){return test("%0-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_zpad(void){return test("%0-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_zpad(void){return test("%0-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_zpad(void){return test("%0-3.3i", -8462);}
//Signed integers with field width and precision with allsign with zeropadding
int		sint_prec_width_ff_pos_allsign_zpad(void){return test("%0+8.5i", 34);}
int		sint_prec_width_ff_neg_allsign_zpad(void){return test("%0+10.5i", -216);}
int		sint_prec_width_ff_zero_allsign_zpad(void){return test("%0+8.5i", 0);}
int		sint_prec_width_nf_pos_allsign_zpad(void){return test("%0+8.3i", 8375);}
int		sint_prec_width_nf_neg_allsign_zpad(void){return test("%0+8.3i", -8473);}
int		sint_prec_width_fn_pos_allsign_zpad(void){return test("%0+3.7i", 3267);}
int		sint_prec_width_fn_neg_allsign_zpad(void){return test("%0+3.7i", -2375);}
int		sint_prec_width_nn_pos_allsign_zpad(void){return test("%0+3.3i", 6983);}
int		sint_prec_width_nn_neg_allsign_zpad(void){return test("%0+3.3i", -8462);}
//Signed integers with field width and precision, left-justified with allsign with zeropadding
int		sint_prec_width_ff_pos_lj_allsign_zpad(void){return test("%0+-8.5i", 34);}
int		sint_prec_width_ff_neg_lj_allsign_zpad(void){return test("%0+-10.5i", -216);}
int		sint_prec_width_ff_zero_lj_allsign_zpad(void){return test("%0+-8.5i", 0);}
int		sint_prec_width_nf_pos_lj_allsign_zpad(void){return test("%0+-8.3i", 8375);}
int		sint_prec_width_nf_neg_lj_allsign_zpad(void){return test("%0+-8.3i", -8473);}
int		sint_prec_width_fn_pos_lj_allsign_zpad(void){return test("%0+-3.7i", 3267);}
int		sint_prec_width_fn_neg_lj_allsign_zpad(void){return test("%0+-3.7i", -2375);}
int		sint_prec_width_nn_pos_lj_allsign_zpad(void){return test("%0+-3.3i", 6983);}
int		sint_prec_width_nn_neg_lj_allsign_zpad(void){return test("%0+-3.3i", -8462);}
//Signed integers of varying size modifiers
char 		ch_pos_1 = 100, ch_neg_1 = -87;
short		sh_pos_1 = 3047, sh_neg_1 = -8875;
int			i_pos_1 = 878023, i_neg_1 = -992744;
long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
int		sint_size_hh_pos_casted(void){return test("%hhi", (char)45);}
int		sint_size_hh_neg_casted(void){return test("%hhi", (char)-45);}
int		sint_size_h_pos_casted(void){return test("%hi", (short)385);}
int		sint_size_h_neg_casted(void){return test("%hi", (short)-385);}
int		sint_size_l_pos_casted(void){return test("%li", (long)32);}
int		sint_size_l_neg_casted(void){return test("%li", (long)-32);}
int		sint_size_ll_pos_casted(void){return test("%lli", (long long)43);}
int		sint_size_ll_neg_casted(void){return test("%lli", (long long)-43);}
int		sint_size_hh_pos_ref(void){return test("%hhi", ch_pos_1);}
int		sint_size_hh_neg_ref(void){return test("%hhi", ch_neg_1);}
int		sint_size_h_pos_ref(void){return test("%hi", sh_pos_1);}
int		sint_size_h_neg_ref(void){return test("%hi", sh_neg_1);}
int		sint_size_l_pos_ref(void){return test("%li", l_pos_1);}
int		sint_size_l_neg_ref(void){return test("%li", l_neg_1);}
int		sint_size_ll_pos_ref(void){return test("%lli", ll_pos_1);}
int		sint_size_ll_neg_ref(void){return test("%lli", ll_neg_1);}
int		sint_size_l_pos_big(void){return test("%li", 22337203685477);}
int		sint_size_l_neg_big(void){return test("%li", -22337203685477);}
int		sint_size_ll_pos_big(void){return test("%lli", 522337203685470);}
int		sint_size_ll_neg_big(void){return test("%lli", -522337203685470);}
//Signed integers of varying size modifiers with some other modifiers
int		sint_size_l_pos_big_zpad(void){return test("%037li", 22337203685477);}
int		sint_size_l_neg_big_prec(void){return test("%.37li", -22337203685477);}
int		sint_size_ll_pos_big_width(void){return test("%37lli", 522337203685470);}
int		sint_size_ll_neg_big_lj(void){return test("%-37lli", -522337203685470);}
int		sint_size_l_pos_big_allsign(void){return test("%+li", 22337203685477);}
//Multiple signed integers in a row of varying sizes
int		sint_size_ll_hh_ll(void){return test("%lli%hhi%lli", ll_pos_1, ch_neg_1, ll_neg_1);}
int		sint_size_h_l_hh(void){return test("%hi%li%hhi", sh_pos_1, l_neg_1, ch_neg_1);}
int		sint_size_l_hh_h(void){return test("%li%hhi%hi", l_neg_1, ch_pos_1, sh_pos_1);}
int		sint_size_n_ll_hh(void){return test("%i%lli%hhi", i_pos_1, ll_neg_1, ch_pos_1);}
int		sint_size_ll_n_l(void){return test("%lli%i%li", ll_neg_1, i_pos_1, l_pos_1);}

//Switching between string and signed integers of various sizes
char	str_1[] = "hello world", str_2[] = "panda", str_3[] = "this is a longer string";
char	str_empty[] = "";
int		hhi_str_lli_str(void){return test("%hhi%s%lli%s", ch_pos_1, str_3, ll_neg_1, str_2);}
int		str_hi_str_li(void){return test("%s%hi%s%li", str_1, sh_neg_1, str_3, l_neg_1);}










































