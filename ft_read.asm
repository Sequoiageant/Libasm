; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.asm                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/17 11:44:37 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/25 12:29:30 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;
            
section .text
global ft_read
extern __errno_location

ft_read:
			push rbp
			mov rbp, rsp
			xor rax, rax
			call __errno_location
			mov r8, rax
			mov rax, 0
			syscall
			cmp rax, 0
			je return
			neg rax
			mov [r8], rax
			mov rax, -1
return:
			leave
			ret
