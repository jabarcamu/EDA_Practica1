arr = []
i = 0
j = 0
for i in range(tam):
    for j in range(0, tam - i - 1):
        if arr[j] > arr[j + 1] :
            arr[j], arr[j + 1] = arr[j + 1], arr[j]