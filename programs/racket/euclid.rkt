#lang racket

(define (euclid a b)
  (define r (modulo a b))
  (define multiplier (/ (- a r) b))
  (write a)
  (write " = ")
  (write b)
  (write "*")
  (write multiplier)
  (write " + ")
  (write r)
  (write )
  (when (not (eq? r 0))
    (euclid b r)))

(euclid 45 25)
