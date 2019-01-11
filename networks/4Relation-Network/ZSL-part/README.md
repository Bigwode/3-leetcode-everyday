# LearningToCompare_ZSL

PyTorch code for CVPR 2018 paper: [Learning to Compare: Relation Network for Few-Shot Learning](https://arxiv.org/abs/1711.06025) (Zero-Shot Learning part)

For Few-Shot Learning part, please visit [here](https://github.com/songrotek/LearningToCompare_FSL).

# Requirements

Python 2.7

Pytorch 0.3

# Data
Download data from [here](http://www.robots.ox.ac.uk/~lz/DEM_cvpr2017/data.zip) and unzip it `unzip data.zip`.

# Run
ZSL and GZSL performance evaluated under GBU setting [1]: ResNet feature, GBU split, averaged per class accuracy.

`AwA1_RN.py` will give you ZSL and GZSL performance on AwA1 with attribute under GBU setting [1].

`AwA2_RN.py` will give you ZSL and GZSL performance on AwA2 with attribute under GBU setting [1].

`CUB_RN.py` will give you ZSL and GZSL performance on CUB with attribute under GBU setting [1].


| Model      |   AwA1 T1    |    u    |    s    |    H    |   CUB T1    |    u    |    s    |    H    |
|------------|---------|---------|---------|---------|---------|---------|---------|---------|
| DAP [2]      |   44.1  |   0.0   |   88.7  |   0.0   |   40.0  |   1.7   |   67.9  |   3.3   |
| CONSE [3]     |   45.6  |   0.4   |   88.6  |   0.8   |   34.3  |   1.6   |   **72.2**  |   3.1   |
| SSE [4]       |   60.1  |   7.0   |   80.5  |   12.9  |   43.9  |   8.5   |   46.9  |   14.4  |
| DEVISE [5]    |   54.2  |   13.4  |   68.7  |   22.4  |   52.0  |   23.8  |   53.0  |   32.8  |
| SJE [6]       |   65.6  |   11.3  |   74.6  |   19.6  |   53.9  |   23.5  |   59.2  |   33.6  |
| LATEM [7]     |   55.1  |   7.3   |   71.7  |   13.3  |   49.3  |   15.2  |   57.3  |   24.0  |
| ESZSL [8]     |   58.2  |   6.6   |   75.6  |   12.1  |   53.9  |   12.6  |   63.8  |   21.0  |
| ALE [9]       |   59.9  |   16.8  |   76.1  |   27.5  |   54.9  |   23.7  |   62.8  |   34.4  |
| SYNC [10]      |   54.0  |   8.9   |   87.3  |   16.2  |   55.6  |   11.5  |   70.9  |   19.8  |
| SAE [11]       |   53.0  |   1.8   |   77.1  |   3.5   |   33.3  |   7.8   |   54.0  |   13.6  |
| [DEM](https://github.com/lzrobots/DeepEmbeddingModel_ZSL) [12] | **68.4** | **32.8** | 84.7  |  **47.3** | 51.7  |   19.6  |  57.9  |  29.2 |
| **RN (OURS)** |68.2  | 31.4  | **91.3**   |  46.7  |  **55.6** |  **38.1**   |  61.4   |  **47.0**  |


| Model      |   AwA2 T1    |    u    |    s    |    H    | 
|------------|---------|---------|---------|---------|
| DAP [2]      |   46.1  |   0.0    |   84.7  |   0.0   |
| CONSE [3]     |   44.5  |   0.5   | 90.6|   1.0   |   
| SSE [4]       |   61.0  |   8.1   |   82.5  |   14.8  |  
| DEVISE [5]    |   59.7  |   17.1  |   74.7  |   27.8  |  
| SJE [6]       |   61.9  |   8.0   |   73.9  |   14.4  |  
| LATEM [7]     |   55.8  |   11.5  |   77.3  |   20.0  | 
| ESZSL [8]     |   58.6  |   5.9   |   77.8  |   11.0  |  
| ALE [9]       |   62.5  |   14.0  |   81.8  |   23.9  | 
| SYNC [10]     |   46.6  |   10.0  |   90.5  |   18.0  |  
| SAE [11]      |   54.1  |   1.1   |   82.2  |   2.2   | 
| [DEM](https://github.com/lzrobots/DeepEmbeddingModel_ZSL) [12] | **67.1** | **30.5** | 86.4 | 45.1| 
| **RN (OURS)** |64.2   | 30.0 | **93.4**  | **45.3** | 






## Citing

If you use this code in your research, please use the following BibTeX entry.

```
@inproceedings{sung2018learning,
  title={Learning to Compare: Relation Network for Few-Shot Learning},
  author={Sung, Flood and Yang, Yongxin and Zhang, Li and Xiang, Tao and Torr, Philip HS and Hospedales, Timothy M},
  booktitle={Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition},
  year={2018}
}
```

## References

- [1] [Zero-Shot Learning - A Comprehensive Evaluation of the Good, the Bad and the Ugly](https://arxiv.org/abs/1707.00600).
  Yongqin Xian, Christoph H. Lampert, Bernt Schiele, Zeynep Akata.
  arXiv, 2017.
- [2] [Attribute-Based Classification forZero-Shot Visual Object Categorization](https://cvml.ist.ac.at/papers/lampert-pami2013.pdf).
  Christoph H. Lampert, Hannes Nickisch and Stefan Harmeling.
  PAMI, 2014.
- [3] [Zero-Shot Learning by Convex Combination of Semantic Embeddings](https://arxiv.org/abs/1312.5650).
  Mohammad Norouzi, Tomas Mikolov, Samy Bengio, Yoram Singer, Jonathon Shlens, Andrea Frome, Greg S. Corrado, Jeffrey Dean.
  arXiv, 2013.
- [4] [Zero-Shot Learning via Semantic Similarity Embedding](https://arxiv.org/abs/1509.04767).
  Ziming Zhang, Venkatesh Saligrama.
  ICCV, 2015.
- [5] [DeViSE: A Deep Visual-Semantic Embedding Model](http://papers.nips.cc/paper/5204-devise-a-deep-visual-semantic-embedding-model.pdf).
  Andrea Frome*, Greg S. Corrado*, Jonathon Shlens*, Samy BengioJeffrey Dean, Marc’Aurelio Ranzato, Tomas Mikolov.
  NIPS, 2013.
- [6] [Evaluation of Output Embeddings for Fine-Grained Image Classification](https://arxiv.org/abs/1409.8403).
  Zeynep Akata, Scott Reed, Daniel Walter, Honglak Lee, Bernt Schiele.
  CVPR, 2015.
- [7] [Latent Embeddings for Zero-shot Classification](https://arxiv.org/abs/1603.08895).
  Yongqin Xian, Zeynep Akata, Gaurav Sharma, Quynh Nguyen, Matthias Hein, Bernt Schiele
  CVPR, 2016.
- [8] [An embarrassingly simple approach to zero-shot learning](http://proceedings.mlr.press/v37/romera-paredes15.pdf).
  Bernardino Romera-Paredes, Philip H. S. Torr.
  ICML, 2015.
- [9] [Label-Embedding for Image Classification](https://arxiv.org/abs/1503.08677).
  Zeynep Akata, Florent Perronnin, Zaid Harchaoui, Cordelia Schmid.
  PAMI, 2016.
- [10] [Synthesized Classifiers for Zero-Shot Learning](https://arxiv.org/abs/1603.00550).
  Soravit Changpinyo, Wei-Lun Chao, Boqing Gong, Fei Sha.
  CVPR, 2016.
- [11] [Semantic Autoencoder for Zero-Shot Learning](https://arxiv.org/abs/1704.08345).
  Elyor Kodirov, Tao Xiang, Shaogang Gong.
  CVPR, 2017.
- [12] [Learning a Deep Embedding Model for Zero-Shot Learning](https://arxiv.org/abs/1611.05088).
  Li Zhang, Tao Xiang, Shaogang Gong.
  CVPR, 2017.
