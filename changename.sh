for file in Day*;
do
    mv "$file" "${file/Day/Day0}"
done
```