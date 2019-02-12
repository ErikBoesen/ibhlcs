#lang racket

(define a 2)

(define (extract str)
  (substring str 4 7))

(extract "The cat is out of the bag")
