#lang racket

(define (euclid a b)
  (define r (modulo a b))
  (define multiplier (/ (- a r) b))
  (fprintf (current-output-port) "~s = ~s * ~s + ~s\n" a b multiplier r)
  (when (not (eq? r 0))
    (euclid b r)))

(euclid 45 25)
