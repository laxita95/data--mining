**1. Summary of Incremental Algorithm:**

The proposed incremental algorithm is performed in two parts. In the first part, the static algorithm is performed over an existing dataset to obtain the cluster label, EigenVectors, and Eigen Values.
Now, in second part, 
	1.The representative points for each data points are obtained for each cluster based on the eigenvectors provided by the static algorithm using equation 7.

	2.Now, the eigen gap heuristic is used to find out the optimal number of clusters based on the Eigen Values obtained from the static algorithm. Once we have the optimal 	 number of clusters, we calculate the optimal number of new data points to be inserted or deleted in the current iteration.

	3.The incremental algorithm generates the instant cluster label for each new data point based on the minimum average distance from the representative values of each 		cluster.

	4.Once the Optimal number of new data points is inserted or old data points are deleted, the next iteration is initiated over the modified data set. If the Optimal 		number of clusters computed using eigengap heuristic is greater than the provided number of clusters then the number of clusters is increased by one in the next 		iteration.
	
The static part of the next iteration generates the cluster label for the data points of the modified data set. Now, we compare the cluster label of each data point to calculate the accuracy of the incremental algorithm with a static algorithm.


**2. Computation of Accuracy:**

The comparison is performed between the final output of an iteration N with the output of the static part of the next iteration i.e. iteration (N+1). We are considering only newly added data points cluster labels for accuracy computation.

The accuracy computation of the proposed algorithm is performed in two parts. In the first part we identify the similar clusters in the final data set with the output cluster label at the end of  iteration N and data set with the output cluster label after the static part of next iteration i.e. iteration (N+1).

To identify the similar cluster we find the distribution of data points of a specific cluster available at the end of iteration N among the clusters available after the static part of the iteration (N+1). For example, consider the experimental data shown in the table below:

	1	2	3	4	5	6	7
1	0	0	0	0	0	8	0
2	45	0	0	0	0	0	0					
3	0	0	0	170	0	0	0			
4	0	116	0	0	0	97	70
5	0	0	0	0	96	0	0
6	0	0	0	0	0	127	
7	0	0	8	0	166	0	42

The rows indicate the clusters available after iteration 1 and the column corresponds to the clusters available after static part of iteration 2. The value in cell (i,j) indicates the total number of data points of  cluster i of iteration 1 assigned to the cluster j available after the static part of iteration 2. For example, cell(1,6) shows that 8 data points of cluster 1 of iteration 1 is labeled as cluster 6 after the static part of iteration 2. Now, according to the above table cluster 1 could be cluster 6 with probability 1, cluster 4 could be cluster 2 with probability 0.41 or cluster 6 with probability 0.35 or cluster 7 with probability 0.24.

Once we have identified the possible similar clusters,, we calculate the accuracy using equation A.

		Accuracy = Hit / (Hit + Miss) ……………………………………………………………………………..A

If a newly added data point has assigned a cluster after the static part of iteration (N+1) among the identical clusters of a cluster assigned after iteration 1 then it will be considered a hit, else it will be a miss.

We are calculating two types of accuracy to evaluate the proposed incremental algorithm. They are:

	1.Strict Accuracy: If we consider a cluster with highest probability among the set of similar clusters 	available after iteration (N+1) as the identical cluster of a 		cluster available after iteration N then the accuracy computed will be strict accuracy. In the above example, in case of strict accuracy the identical cluster of 		cluster 4 available after iteration 1 is cluster 2 available after static part of iteration 2. 	Since, cluster 2 has the highest probability i.e. 0.41. So, if a newly 		added data point is assigned cluster 4 after iteration 1 and will be assigned a cluster 2 after static part of iteration 2, it will be considered a hit or it will be a 	miss.

	2.Relaxed accuracy: : If we consider all clusters among the similar clusters available after iteration (N+1) as the identical cluster of a cluster available after 		iteration N then the accuracy computed will be relaxed accuracy. In the above example, in case of relaxed accuracy the identical cluster of cluster 4 available after 		iteration 1 are cluster 2,6, and 7 available after static part of iteration 2.  So, if a newly added data point is assigned cluster 4 after iteration 1 and will be 		assigned any cluster among cluster 2,6, and 7 after static part of iteration 2, it will be considered a hit or it will be a miss.
