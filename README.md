# SpigotC
Spigot Algorithm in pure C - Compiled using GCC from CodeBlocks

In the realm of mathematical constants, π (pi) holds a special place due to its ubiquity and significance in various fields. Calculating the digits of π has been a fascinating pursuit for mathematicians throughout history. One such algorithm that caught the attention of enthusiasts is the Spigot algorithm. In this post, we will dive into the Spigot algorithm, exploring its inner workings and how it enables us to generate the digits of π digit by digit.

What is the Spigot Algorithm?
The Spigot algorithm, also known as the Spigot series algorithm, is a method for generating the digits of π sequentially, rather than computing the entire value at once. It was first introduced by Stanley Rabinowitz and Stan Wagon in 1995, adding to the repertoire of existing algorithms like the famous Bailey-Borwein-Plouffe (BBP) formula.

The Spigot algorithm draws inspiration from the concept of a "spigot" or a faucet, where the digits of π flow out one by one, as if the constant is being poured out digit by digit. It achieves this digit-by-digit generation by simulating the steps of long division.

How does it work?
The Spigot algorithm leverages the idea that the digits of π can be calculated by dividing a series of numbers iteratively. Here's a step-by-step breakdown of how the algorithm works:

Initialization: Start with an initial array representing the decimal part of π, where each element of the array corresponds to a digit.
Iteration: Repeat the following steps for each desired digit of π:
a. Multiply: Multiply each digit in the array by the base (10) and add a carry from the previous iteration.
b. Divide: Perform long division to calculate the quotient and remainder.
c. Update: Update the array with the remainder, and set the carry for the next iteration as the product of the quotient and the current index.
d. Extract: Extract the leading digit from the quotient and output it.
Repeat: Continue the iteration until the desired number of digits of π is obtained.
Benefits and Limitations:
The Spigot algorithm offers several advantages:

Incremental Calculation: Unlike some other algorithms, the Spigot algorithm generates π digit by digit, allowing for streaming output and reducing memory requirements.
Simplicity: The algorithm's implementation is relatively straightforward, making it accessible for educational purposes or small-scale calculations.
However, the Spigot algorithm also has its limitations:

Efficiency: While the algorithm provides a novel approach to calculating π, it is not the most efficient method when it comes to generating a large number of digits.
Complexity: Although conceptually simple, the details of long division and array manipulation within the algorithm can be challenging to understand and implement correctly.
Conclusion:
The Spigot algorithm provides an intriguing perspective on calculating the digits of π. Its digit-by-digit approach offers a unique way to explore the never-ending sequence of π. Although not as efficient as some other algorithms, the Spigot algorithm serves as a valuable tool for learning and experimentation.

By studying algorithms like the Spigot algorithm, we gain a deeper appreciation for the beauty and complexity of mathematics. Whether you're a mathematics enthusiast, a programmer, or simply curious about the world of numbers, the Spigot algorithm opens a door to a captivating journey into the realm of π.

References:

Rabinowitz, S. and Wagon, S. (1995). A Spigot Algorithm for the Digits of Pi. Retrieved from https://www.mathpropress.com/stan/bibliography/spigot.pdf
