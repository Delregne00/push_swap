<div align="center">

# push_swap

**An efficient sorting algorithm using two stacks with a limited set of operations**

*The first algorithmic project of 42 School - sort integers with the minimum possible number of moves*

---

</div>

## Demo
<div align="center">

![push_swap demonstration](demo/demo.gif)

*Sorting integers using stack operations with optimal move sequences*

</div>

---

## Objective

Sort a stack of integers using only two stacks (A and B) and a limited set of operations. The challenge is to find the most efficient algorithm that uses the **minimum number of moves** to sort any given set of integers. At the beginning, you have one stack called stack A with all your numbers, and with the help of specific operations, all numbers must end up sorted in stack A.

---

## Available Operations

<div align="center">

| Operation | Description | Operation | Description |
|:---------:|:------------|:---------:|:------------|
| **sa** | Swap first 2 elements of stack A | **sb** | Swap first 2 elements of stack B |
| **ss** | Execute sa and sb simultaneously | **pa** | Push top of B to top of A |
| **pb** | Push top of A to top of B | **ra** | Rotate stack A up (first becomes last) |
| **rb** | Rotate stack B up (first becomes last) | **rr** | Execute ra and rb simultaneously |
| **rra** | Reverse rotate stack A (last becomes first) | **rrb** | Reverse rotate stack B (last becomes first) |
| **rrr** | Execute rra and rrb simultaneously | | |

</div>

---

## Usage

### Basic Usage
```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Output: sequence of operations to sort the numbers
pb
pb
sa
pa
pa
```

### With Checker (Bonus)
```bash
# Verify that the operations correctly sort the numbers
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
# Output: OK (if sorted correctly) or KO (if not)
```

### Error Handling
```bash
# Invalid input examples
./push_swap 2 1 3 2        # Error: duplicates
./push_swap 2 one 3        # Error: non-integer
./push_swap 999999999999   # Error: overflow
```

---

## Installation

<details>
<summary><b>Prerequisites</b></summary>

- **GCC** compiler
- **Make** build system  
- **Standard C library**

</details>

### Build & Run

```bash
# Clone the repository
git clone https://github.com/Delregne00/push_swap.git
cd push_swap

# Compile the project
make

# Run with a list of integers
./push_swap 3 2 1 5 4

# Compile bonus (checker program)
make bonus

# Use checker to validate operations
echo "sa pb pb" | ./checker 3 2 1
```

---

## Algorithm Implementation

The project implements **optimized sorting algorithms** designed specifically for the stack-based constraints.

<details>
<summary><b>Algorithm Strategy</b></summary>

### **Core Approach**
The algorithm uses a combination of chunking and optimal move calculation to efficiently sort numbers between two stacks. The main strategy involves:

1. **Analysis Phase**: Determine the optimal algorithm based on stack size
2. **Chunking Phase**: Divide numbers into manageable chunks for large datasets  
3. **Optimization Phase**: Calculate minimum moves for each operation
4. **Execution Phase**: Output the optimal sequence of operations

### **Size-Based Algorithm Selection**
- **≤ 3 numbers**: Direct sorting with maximum 3 operations
- **4-5 numbers**: Optimized small-set algorithm (≤ 12 operations)
- **6-100 numbers**: Medium-set chunk algorithm
- **101-500 numbers**: Large-set optimized algorithm with advanced chunking

</details>

<details>
<summary><b>Optimization Techniques</b></summary>

### **Move Optimization**
- **Combined Operations**: Use `rr`, `rrr`, `ss` when possible instead of separate operations
- **Cost Calculation**: Calculate the exact cost of moving any element to its target position
- **Chunk Strategy**: Divide the dataset into chunks of optimal size based on total numbers
- **Rotation Efficiency**: Choose between `ra`/`rra` based on element position

### **Advanced Optimizations**
- **Longest Increasing Subsequence**: Find the longest sequence already in order to minimize initial moves
- **Target Position Analysis**: Calculate optimal placement for each number
- **Bidirectional Cost Analysis**: Compare costs of different rotation directions

</details>

<details>
<summary><b>Algorithm Variations</b></summary>

### **Popular Approaches**
1. **Radix Sort Adaptation**: Using binary representation and two stacks instead of 10 buckets
2. **Turk Algorithm**: Cost-based approach calculating optimal moves for each element  
3. **Chunk-based Algorithm**: Dividing numbers into chunks for efficient processing
4. **Hybrid Approaches**: Combining multiple strategies based on input characteristics

</details>

---

## Performance Requirements

The grade depends on how efficient the program's sorting process is:

<div align="center">

| Numbers | Maximum Operations | Grade |
|:-------:|:-----------------:|:-----:|
| **3** | 3 operations | Pass/Fail |
| **5** | 12 operations | Pass/Fail |
| **100** | 1,084 operations | ⭐⭐⭐⭐⭐ |
| | 1,100 operations | ⭐⭐⭐⭐ |
| | 1,300 operations | ⭐⭐⭐ |
| | 1,500 operations | ⭐⭐ |
| | > 1,500 operations | ⭐ |
| **500** | 6,785 operations | ⭐⭐⭐⭐⭐ |
| | 7,000 operations | ⭐⭐⭐⭐ |
| | 8,500 operations | ⭐⭐⭐ |
| | 10,000 operations | ⭐⭐ |
| | > 10,000 operations | ⭐ |

</div>

---

## Testing & Validation

### Built-in Testing
```bash
make test3      # Test with 3 random numbers
make test5      # Test with 5 random numbers  
make test100    # Test with 100 random numbers
make test500    # Test with 500 random numbers
```

### Manual Testing
```bash
# Generate random numbers and test
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Performance testing
for i in {1..10}; do ARG=$(seq 1 500 | shuf | tr '\n' ' '); echo -n "Test $i: "; ./push_swap $ARG | wc -l; done
```

### Visualization
Use push-swap visualizers to see the sorting process graphically:
```bash
# Install push_swap GUI (requires Python + tkinter)
pip install push-swap-gui

# Use with your push_swap program
push_swap_gui
```

---

## Error Handling

The program handles various error conditions:

<table>
<tr>
<td width="50%">

**Input Validation:**
- Non-integer arguments
- Integer overflow/underflow
- Duplicate numbers
- Empty argument list

</td>
<td width="50%">

**Runtime Validation:**
- Invalid operation sequences (checker)
- Memory allocation failures
- Malformed input formats

</td>
</tr>
</table>

---

## Documentation

For detailed technical documentation about the implementation:

**[Complete Technical Wiki](https://app.devin.ai/wiki/Delregne00/push_swap)**

<details>
<summary><b>The wiki covers:</b></summary>

- Detailed algorithm implementation and analysis
- Mathematical complexity analysis
- Step-by-step algorithm walkthroughs
- Performance optimization techniques
- Testing strategies and benchmarking
- Common pitfalls and debugging tips

</details>

---

## Built With

<table>
<tr>
<td width="50%">

**Core Technologies:**
- **Language**: C (C99 standard)
- **Build System**: Custom Makefile
- **Data Structures**: Circular doubly linked lists
- **Algorithms**: Custom sorting implementations

</td>
<td width="50%">

**Custom Libraries:**
- **libft**: Custom utility library
- **ft_printf**: Custom formatted output
- **Memory management**: Custom allocation handling

</td>
</tr>
</table>

---

## Development Environment

### Project Structure
```
push_swap/
├── src/                    # Core algorithm implementation
│   ├── algorithm/         # Sorting algorithm logic
│   ├── operations/        # Stack operation functions
│   ├── parsing/           # Input validation and parsing
│   └── utils/             # Utility and helper functions
├── includes/              # Header files and definitions
├── checker_src/           # Bonus checker program source
├── libft/                 # Custom utility library
├── demo/                  # Algorithm demonstrations
├── tests/                 # Test cases and scripts
└── Makefile              # Build configuration
```

### Build Targets
```bash
make          # Build push_swap executable
make bonus    # Build checker program  
make clean    # Remove object files
make fclean   # Full clean (remove all generated files)
make re       # Rebuild everything from scratch
make test     # Run comprehensive tests
```

---

## Key Features

<div align="center">

**Optimal Sorting** • **Multiple Algorithms** • **Performance Analysis** • **Error Handling** • **Comprehensive Testing** • **Memory Efficiency**

</div>

<table>
<tr>
<td width="50%">

**Core Features:**
- Highly optimized sorting algorithms
- Multiple algorithm strategies based on input size
- Comprehensive input validation and error handling
- Performance analysis and benchmarking tools

</td>
<td width="50%">

**Technical Features:**
- Zero memory leaks with proper cleanup
- Efficient data structure implementation
- Cross-platform compatibility
- Extensive test suite with automated validation

</td>
</tr>
</table>

---

## 42 School Requirements

This project fulfills **all requirements** for the **push_swap** project at 42 School:

<div align="center">

| Requirement | Status |
|:------------|:------:|
| Sort integers using only given operations | ✅ |
| Minimize number of operations | ✅ |
| Handle edge cases (3, 5, 100, 500 numbers) | ✅ |
| Comprehensive error handling | ✅ |
| Input validation and duplicate detection | ✅ |
| Bonus: checker program implementation | ✅ |
| No memory leaks | ✅ |
| Efficient algorithms meeting performance thresholds | ✅ |

</div>

---

<div align="center">

**Developed by [Delregne00] as part of the 42 School curriculum**

</div>
