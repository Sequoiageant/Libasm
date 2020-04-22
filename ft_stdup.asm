; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_stdup.asm                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/04/22 16:19:39 by julnolle          #+#    #+#              ;
;    Updated: 2020/04/22 16:20:15 by julnolle         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

            section .text
            global ft_strdup

ft_strdup:
			xor		rax, rax
			xor		rcx, rcx
			jmp		compare

