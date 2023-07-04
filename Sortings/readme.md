 # Implementations of different sorting algorithms::
 <br><br><br>
 ## * Insertion Sort:)
  <b>STEPS:</b>
  <i>
    <ol>
        <li>assume first element is sorted perfectly as a sorted list.</li>
        <li>take 2nd element</li>
        <li>look where this element is fitted in sorted list as in 1</li>
        <li>now two items are in supposed sorted list </li>
        <li>take 3rd element and do same as in step 3 & 4</li>
        <li>then 4th then 5th and soon untill last element</li>
        <li>for more detail:-https://www.programiz.com/dsa/insertion-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Selection Sort:)
        <h3>main idea:Find the minm element from unsorted list and swap it at the beginning of list</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>assume first element as minm and compare it with rest amd change minm if any smallest element is found compared to supposed smallest element(minm).</li>
        <li>now assume  2nd element as minm and compare it to latter elements,find minm as same as in step 1</li>
        <li>Then assume 3rd 4th 5th ....2nd last elements as minm and do same as in step 2</li>
        <li>for more detail:-https://www.programiz.com/dsa/selection-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Bubble Sort:)
    <h3>main idea:Repeatedly sort two adjacent element if they are in wrong order.</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>Compare first and second ,if wrong order swap them</li>
        <li>now compare second and third if wrong swap them</li>
        <li>now compare third and fourth if wrong swap them and soon untill u compared last n second last</li>
        <li>after this process ends last one is sorted perfectly .</li>
        <li>Then do the same process repeatedly as in 1 ,2,3 untill comparison of unsorted last two elements.</li>
        <li>for more detail:-https://www.programiz.com/dsa/bubble-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Radix/Bucket Sort:)
    <h3>main idea:Comparison of ones tens hundredth ..........positioned value of elements/data and arrange it accordingly.</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>for more detail:-https://www.programiz.com/dsa/radix-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Merge Sort:)
    <h3>main idea:Divide and conquer i.e. divide the list in sublists and sort them accodingly.</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>Split the list into each single sublists for a element. </li>
        <li>take sublists in pair if available sort them and merge two sublists into one .if not available do nth left the odd one for next step </li>
        <li>Do this process agai and again to get out sorted array. </li>
        <li>FOLLOWING POINTS MOST CONSIDER WHILE DIVIDING :- </li>
        <li>we consider si=starting index and ei=ending index and we calculate mid=integer(ei-si)/2 .Repeat it untill a single element sublist are obtained(base case). </li>
        <li>FOLLOWING POINTS MOST CONSIDER WHILE CONQUERING :- </li>
        <li>We make of empty array with required slots </li>
        <li>then we look smallest element among two sorted sublists put smallest to first of above created array and largest among them is compared with next smallest of another sublist and put smallest in second index and process is continued untill sorting is completed</li>
        <li>copy the above data of array in original array/parent array</li>
        <li>This process is repeated untill the merging completed and sorted array is stored in out original/root array </li>
        <li>for more detail:-https://www.programiz.com/dsa/merge-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Quick Sort:)
    <h3>main idea:Assuming pivot element and partitioning it as smallest goes at left side and largest goes at right side.</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>Set one element as pivot element say the last element,initialize/reassign a helper variable i=low-1{low=leftmost partioned first element index}</li>
        <li>Compare pivot with rest of other and make two partitions left and right.Doing this we sorted pivot at correct position.</li>
        <li>Now doing the same as in step 1 and 2 for each partition we repeat the process such that pivot supposed element are sorted in each iteration with the help of helper variable. </li>
        <li>for more detail:-https://www.programiz.com/dsa/quick-sort</li>
    </ol>
  </i>
 <br><br><br>
 ## * Exchange Sort:)
    <h3>main idea:Making the elements sorted one by one from starting to end.</h3>
    <b>STEPS:</b>
  <i>
    <ol>
        <li>Set two variable X and Y such that X=0 for representing element in first and Y=X+1 travels throughout the array .If iteration is completed X increase by 1.Y re intialized as X+1.</li>
        <li>For X=0 compare 0th index element with Yth index element {from X+1 to array.length} if smaller in Yth swap with Xth.</li>
        <li>After the end of 1 iteration as above first is sorted X++ y=X+1 and do same as step 2. </li>
        <li>for more detail:-https://www.codingunit.com/exchange-sort-algorithm</li>
    </ol>
  </i>
 <br><br><br>