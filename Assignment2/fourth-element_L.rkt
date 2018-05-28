;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname fourth-element_L) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(define fourth-element
  (lambda(lst)
    (let ((removed (rest(rest(rest lst)))))
      (cond [(empty? removed) empty]
            [(list? removed) (first removed)]))))