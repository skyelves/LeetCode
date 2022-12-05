cmake_minimum_required(VERSION 3.14)
project(Leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(Leetcode main.cpp solution.h 1_twoSum.h 2_addTwoNumbers.h 1021_removeOutermostParentheses.h 2166_designBitset.h
        316_removeDuplicateLetters.h 236_lowestCommonAncestor.h 2030_smallestK-LengthSubsequenceWithOccurrencesofaLetter.h 2354_numberOfExcellentPairs.h 2353_designAFoodRatingSystem.h
        2259_removeDigitFromNumbertoMaximizeResult.h 2260_minimumCardPickup.h 2261_countDistinct.h 2262_appealSum.h
        2248_intersection.h 2249_countLatticePoints.h 2250_countRectangles.h 2251_fullBloomFlowers.h
        114_flatten.h 2003_smallestMissingValueSubtree.h 242_isAnagram.h 890_findAndReplacePattern.h 1044_longestDupSubstring.h 916_wordSubsets.h 307_numArray.h
        378_kthSmallest.h 668_findKthNumber.h 729_myCalendar.h 731_myCalendarTwo.h 732_myCalendarThree.h 377_combinationSum4.h
        98_isValidBST.h 3_lengthOfLongestSubstring.h 1996_numberOfWeakCharacters.h 126_findLadders.h 127_ladderLength.h 433_minMutation.h 2157_groupStrings.h
        1338_minSetSize.h 128_longestConsecutive.h 383_canConstruct.h 691_minStickers.h 637_averageOfLevels.h 341_NestedIterator.h 987_verticalTraversal.h 29_divide.h
        122_maxProfit.h 11_maxArea.h 198_houseRobber.h 53_maxSubArray.h 1010_numPairsDivisibleBy60.h 1836_deleteDuplicatesUnsorted.h 1209_removeDuplicates.h 322_coinChange.h
        1328_breakPalindrome.h 1356_sortByBits.h 647_countSubstrings.h 780_reachingPoints.h 49_groupAnagrams.h 5_longestPalindrome.h 516_longestPalindromeSubseq.h
        1396_UndergroundSystem.h 430_flatten.h 1029_twoCitySchedCost.h 394_decodeString.h 380_RandomizedSet.h 1244_Leaderboard.h 1472_BrowserHistory.h 253_minMeetingRooms.h
        723_candyCrush.h 1169_invalidTransactions.h 1656_OrderedStream.h 1274_countShips.h 797_allPathsSourceTarget.h 140_wordBreak.h 200_numIslands.h 56_merge.h 146_LRUCache.h
        314_verticalOrder.h 1583_unhappyFriends.h 445_addTwoNumbers.h 994_orangesRotting.h 1375_numTimesAllBlue.h 1531_getLengthOfOptimalCompression.h 1444_ways.h
        370_getModifiedArray.h 2361_minimumCosts.h 16_threeSumClosest.h 259_threeSumSmaller.h 560_subarraySum.h 974_subarraysDivByK.h 36_isValidSudoku.h 1307_isSolvable.h
        295_MedianFinder.h 88_merge.h 15_threeSum.h 18_fourSum.h 696_countBinarySubstrings.h 1507_reformatDate.h 1048_longestStrChain.h 1153_canConvert.h 1381_CustomStack.h
        548_splitArray.h 555_splitLoopedString.h 666_pathSum.h 678_checkValidString.h 1857_largestPathValue.h 221_maximalSquare.h 739_dailyTemperatures.h 488_findMinStep.h
        1614_maxDepth.h 23_mergeKLists.h 124_maxPathSum.h 773_slidingPuzzle.h 1650_lowestCommonAncestor.h 1326_minTaps.h 215_findKthLargest.h 935_knightDialer.h 1347_minSteps.h
        117_connect.h 1249_minRemoveToMakeValid.h 79_wordSearch.h 582_killProcess.h 20_validParentheses.h 38_countAndSay.h 1200_minimumAbsDifference.h 72_minDistance.h 45_jumpGame.h
        91_numDecodings.h 212_findWords.h 611_triangleNumber.h 964_leastOpsExpressTarget.h 33_rotatedSortedArray.h 153_findMinRotated.h 81_rotatedSortedArray2.h
        154_findMinimuminRotatedSortedArray2.h 1236_webCrawler.h 252_canAttendMeetings.h 2402_mostBooked.h 19_removeNthFromEnd.h 387_firstUniqChar.h 1047_removeDuplicates.h
        42_trappingRainWater.h 69_sqrt.h 21_MergeTwoSortedLists.h 29_divide.h 1506_findRootofN-AryTree.h 827_largestIsland.h 435_eraseOverlapIntervals.h 662_widthOfBinaryTree.h 437_pathSum.h 347_topKFrequent.h 518_coinChange2.h 46_permutation.h 213_houseRobber2.h 337_houseRobber3.h 301_removeInvalidParentheses.h 1963_minSwaps.h 656_cheapestJump.h 622_MyCircularQueue.h 47_Permutations2.h 54_spiralOrder.h 61_rotateRight.h 135_candy.h 2115_findAllRecipes.h 399_calcEquation.h 286_wallsAndGates.h 692_topKFrequent.h 460_LFUCache.h 1366_rankTeams.h 1698_countDistinct.h 1787_minXORChanges.h 1823_findTheWinner.h 1977_numberOfCombinations.h 308_NumMatrix.h 443_stringCompression.h 254_getFactors.h 716_maxStack.h 155_minStack.h 4_findMedianSortedArrays.h 311_sparseMatrixMultiplication.h 22_generateParenthesis.h 617_mergeTwoBinaryTrees.h 77_Combinations.h 300_lengthOfLIS.h 1702_maximumBinaryString.h 329_longestIncreasingPath.h 471_encodeStringwithShortestLength.h 428_serializeAndDeserializeN-aryTree.h 362_HitCounter.h 798_smallestRotationwithHighestScore.h 149_maxPointsOnaLine.h "158_readNCharactersGivenRead4II .h" 1900_earliestAndLatest.h 895_FreqStack.h 1114_printInOrder.h "1115_printFooBarAlternately .h" 1116_zeroEvenOdd.h 1117_buildingH2O.h 1188_BoundedBlockingQueue.h)