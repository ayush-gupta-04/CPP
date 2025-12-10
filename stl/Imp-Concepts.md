# Pushing a vector<int> to a vector<vector<int>>.
  ```cpp
      vector<vector<int>> ans;
      vector<int> list = {1,2,3};
      
      ans.push_back(list);
      
  ```
- This Pushes a copy of list to ans.
- Modifying the list later won't change anything inside ans.

 ```cpp
      vector<vector<int>*> ans;
      vector<int> list = {1,2,3};
      
      ans.push_back(&list);
      
  ```

- This Pushes a ref of list to ans.
- Modifying the list later will change the list inside ans.
