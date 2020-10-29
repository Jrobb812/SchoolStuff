(defvar MyList)
(defparameter *unionPar* '())
(defparameter *unionPar2* '())
(defparameter *aList* '())


(defun myList
    (MyList (list 4 list(7 22) "art" list("math" list(8) 99) 100)))

(defun leapYear
    (loop for i from cdr(leapList) upto 2020 by 4 collect i)
        (cond(cdr(leapList)))
    )
)

(defun avg (aList)
    (defun sum (x))
    (if (aList)
        (avg (cdr list) 
            (+ sum (car list)) 
            (+ 1 n))
    (/ sum n))
)

(defun merge-lists (lists)
  (let ((rv (make-hash-table :test #'equal)))
         (mapcar (lambda (list)
           (mapcar (lambda (x) (push x (gethash (car list) rv nil))) (cdr list)))
                   lists)
    (loop for key being the hash-keys of rv
          collect (cons key (reverse (gethash key rv))))))