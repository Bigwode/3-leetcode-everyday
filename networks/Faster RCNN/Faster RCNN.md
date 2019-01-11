### 数据读取部分

Dataset和TestDataset。

VOCBboxDataset

_\_getitem__(self, idx):返回的是：array

```python
img:(3, 375,500):0-255
bbox:(N,4)
label:(N,)
difficult:,(N,):[0,0]
# 再经过transform之后：
img:(3, 600,800)
bbox:(N,4)
label:(N,)
scale:1.6
```



### 模型搭建部分`FasterRCNNVGG16(FasterRCNN)`

#### 1、Region Proposal Network

```python
return:
rpn_locs: Tensor[1, 18648, 4]
rpn_scores: Tensor[1, 18648, 2]
rois: ndarray[2000, 4]
roi_indices: [2000]
anchor: ndarray[18648, 4]
```

#### 2、VGG16ROIHead

```python
roi_cls_locs:[128, 84]
roi_scores:  [128, 21]
```

#### 3、FasterRCNNTrainer 损失

AnchorTargetCreator()

```python
loc  : (18648, 4)
label: (18648,)
```

ProposalCreator()

```python
roi:(2000,4)
```

ProposalTargetCreator()

```python
sample_roi: [128, 4]
gt_roi_loc: [128, 4]
gt_roi_label:[128,]
```

#### 4、forward()

```python
feature:[1,512,37,50] -> rpn
_fast_rcnn_loc_loss(pred_loc, gt_loc, gt_label, sigma)
pred_loc:(18981,4), 
gt_loc:(18981,4), 
gt_label:(18981), 
sigma:3.0
F.cross_entropy(rpn_score, gt_rpn_label.cuda(), ignore_index=-1)
rpn_score:  [18981,2]
gt_rpn_label:[18981]
```





