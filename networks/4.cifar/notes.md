## Notes

```python
parser.add_argument('-c', action='store_true')  
# store_true是指带触发action时为真，不触发为假。
```

AUC(Area Under the Curve of ROC)只能用于二分类模型的评价指标。

ROC(Receiver Operating Characteristic Curve)操作者接收特征曲线。

横轴是 FPR(False Positive Rate)，纵轴是TPR(True Positive Rate).

要按照预测的概率值从大到小排序，之后再计算FPR和TPR.

