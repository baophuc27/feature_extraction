# C version of feature extractor

------------------------------

## Libraries:
I have used only one library for implementing, and one for testing on this version. 
- [EIGEN](https://gitlab.com/libeigen/eigen) : Basic matrix storage and manipulation.
- [CATCHTEST](https://github.com/catchorg/Catch2) : C++ Testing framework.

---------------------
## Testing:
- I used unit test for some common cases such as horizontal line, vertical line, cubic line,...
- I manually tested for another cases by verifying my results on [BEZIER DEMO](https://www.desmos.com/calculator/cahqdxeshd).
- It also can be used for multiple bezier curves by splitting it into small parts.
## Testcases:
I tested this implementation by using some Generate points of character from 0 to 9.
### Testcase 0:
- Original points
<img src="bezier-data/original/0.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/0a.png" width="259"></td>
<td><img src="bezier-data/results/0b.png"></td>
</tr>
</table>

### Testcase 1:
- Original points
<img src="bezier-data/original/1.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/1a.png" width="259"></td>
<td><img src="bezier-data/results/1b.png"></td>
<td><img src="bezier-data/results/1c.png"></td>
</tr>
</table>


### Testcase 2:
- Original points
<img src="bezier-data/original/2.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/2a.png" width="259"></td>
<td><img src="bezier-data/results/2b.png"></td>
<td><img src="bezier-data/results/2c.png"></td>
</tr>
</table>

### Testcase 3:
- Original points
<img src="bezier-data/original/3.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/3a.png" width="259"></td>
<td><img src="bezier-data/results/3b.png"></td>
</tr>
</table>


### Testcase 4:
- Original points
<img src="bezier-data/original/4.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/4a.png" width="259"></td>
<td><img src="bezier-data/results/4b.png"></td>
</tr>
</table>


### Testcase 5:
- Original points
<img src="bezier-data/original/5.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/5a.png" width="259"></td>
<td><img src="bezier-data/results/5b.png"></td>
</tr>
</table>


### Testcase 6:
- Original points
<img src="bezier-data/original/6.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/6a.png" width="259"></td>
<td><img src="bezier-data/results/6b.png"></td>
</tr>
</table>


### Testcase 7:
- Original points
<img src="bezier-data/original/7.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/7a.png" width="259"></td>
<td><img src="bezier-data/results/7b.png"></td>
</tr>
</table>


### Testcase 8:
- Original points
<img src="bezier-data/original/8.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/8a.png" width="259"></td>
<td><img src="bezier-data/results/8b.png"></td>
<td><img src="bezier-data/results/8c.png"></td>
</tr>
</table>


### Testcase 9:
- Original points
<img src="bezier-data/original/9.PNG">
- Generate curves
<table>
<tr>
<td><img src="bezier-data/results/9a.png" width="259"></td>
<td><img src="bezier-data/results/9b.png"></td>
</tr>
</table>

### Testcase 10:
- Original points
<img src="bezier-data/original/eq.PNG">
- Generate 10 curves (with additional off stroke points), and 6 curves (without off stroke points)

### Testcase 11:
- Original points
<img src="bezier-data/original/eq5.PNG">
- Generate 9 curves

### Testcase 12:
- Original points
<img src="bezier-data/original/eq2.PNG">
- Generate 12 curves

### Testcase 13:
- Original points
<img src="bezier-data/original/eq3.PNG">
- Generate 13  curves

### Testcase 14:
- Original points
<img src="bezier-data/original/eq4.PNG">
- Generate 17 curves