#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  
  struct CountsByUsage counts = {0, 0, 0};
  counts.lowCount=0;
  counts.mediumCount=0;
  counts.highCount=0;
  for(int i=0;i<nBatteries;i++){
      
  if(cycles[i]>=0 && cycles[i]<310){
      counts.lowCount++;
  }
  else if(cycles[i]>=310 && cycles[i]<930){
      counts.mediumCount++;
  }
  else if(cycles[i]>=930){
      counts.highCount++;
  }
 }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Low count is: %d\n",counts.lowCount);
  printf("Med count is: %d\n",counts.mediumCount);
  printf("High count is: %d\n",counts.highCount);
  printf("Done counting :)\n");
}

void testBucketingByNumberOfCycles1() {
  const int chargeCycleCounts[] = {0, -1, 929, 310, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 1);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Low count is: %d\n",counts.lowCount);
  printf("Med count is: %d\n",counts.mediumCount);
  printf("High count is: %d\n",counts.highCount);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  testBucketingByNumberOfCycles1();
  return 0;
}
