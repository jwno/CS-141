;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-advanced-reader.ss" "lang")((modname is-increasing) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #t #t none #f () #f)))
(define is-increasing?
  (lambda(lst)
    (cond
      [(empty? lst) #t]
      [(empty? (rest lst)) #t]
      [(> (first lst) (first(rest lst))) #f]
      [else (is-increasing? (rest lst))])))