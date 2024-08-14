
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::vector<int> createVector(std::size_t count)
{
	std::vector<int> vec(count);

	for (int i = 0; i < count; ++i) {
		vec[i] = i % 11; // Fill with values ​​from 0 to 10
	}
	return vec;
}

std::mutex locer;
void calculateSum(const std::vector<int>& vec, int startIndex, int lastIndex, long& sum)
{
	for (int i = startIndex; i <= lastIndex; ++i)
	{
		locer.lock();
		sum += vec[i];
		locer.unlock();
	}
}

int main()
{
	constexpr int size = 5;
	int arr[size] = { 1000, 10000, 100000, 1000000, 10000000 };

	////////////////////////////////////////////////////
	///////// Task1_a

	std::cout << "------ Task: 1 a ------" << std::endl;
	std::cout << "Number of threads: 1" << std::endl << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "Number of elements: " << arr[i] << std::endl;

		std::vector<int> vec = createVector(arr[i]);

		long sum = 0;
		auto start = std::chrono::high_resolution_clock::now();

		std::thread t1(calculateSum, std::cref(vec), 0, vec.size() - 1, std::ref(sum));
		t1.join();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		std::cout << "Sum: " << sum << " Time: " << duration.count() << std::endl << std::endl;
	}

	////////////////////////////////////////////////////
	///////// Task1_b

	std::cout << "------ Task: 1 b ------" << std::endl;
	std::cout << "Number of threads: 2" << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Number of elements: " << arr[i] << std::endl;

		std::vector<int> vec = createVector(arr[i]);

		long sum = 0;
		auto start = std::chrono::high_resolution_clock::now();

		int halfSize = vec.size() / 2;

		std::thread t1(calculateSum, std::cref(vec), 0, halfSize, std::ref(sum));
		std::thread t2(calculateSum, std::cref(vec), halfSize + 1, vec.size() - 1, std::ref(sum));
		t1.join();
		t2.join();

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		std::cout << "Sum: " << sum << " Time: " << duration.count() << std::endl << std::endl;
	}

	////////////////////////////////////////////////////
	///////// Task1_с

	std::cout << "------ Task: 1 c ------" << std::endl;
	unsigned int numThreads = std::thread::hardware_concurrency(); // Number of hardware threads
	std::cout << "Number of threads: " << numThreads << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Number of elements: " << arr[i] << std::endl;

		std::vector<int> vec = createVector(arr[i]);

		long sum = 0;
		auto start = std::chrono::high_resolution_clock::now();

		int chunkSize = vec.size() / numThreads;
		std::vector<std::thread> threads;

		for (unsigned int j = 0; j < numThreads; ++j)
		{
			int startIdx = j * chunkSize;
			int endIdx = (j == numThreads - 1) ? vec.size() - 1 : startIdx + chunkSize - 1;

			threads.emplace_back(calculateSum, std::cref(vec), startIdx, endIdx, std::ref(sum));
		}

		for (auto& t : threads)
		{
			t.join();
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		std::cout << "Sum: " << sum << " Time: " << duration.count() << std::endl << std::endl;
	}

	////////////////////////////////////////////////////
	///////// Task1_d

	std::cout << "------ Task: 1 d ------" << std::endl;
	unsigned int numThreads2 = 2 * std::thread::hardware_concurrency(); // Twice the number of hardware threads
	std::cout << "Number of threads: " << numThreads2 << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Number of elements: " << arr[i] << std::endl;

		std::vector<int> vec = createVector(arr[i]);

		long sum = 0;
		auto start = std::chrono::high_resolution_clock::now();

		int chunkSize = vec.size() / numThreads2;
		std::vector<std::thread> threads;

		for (unsigned int j = 0; j < numThreads2; ++j)
		{
			int startIdx = j * chunkSize;
			int endIdx = (j == numThreads2 - 1) ? vec.size() - 1 : startIdx + chunkSize - 1;

			threads.emplace_back(calculateSum, std::cref(vec), startIdx, endIdx, std::ref(sum));
		}

		for (auto& t : threads)
		{
			t.join();
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		std::cout << "Sum: " << sum << " Time: " << duration.count() << std::endl << std::endl;
	}
}

