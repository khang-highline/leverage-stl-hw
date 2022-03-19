def calculate_trapped_rain_water(my_list):
    drops = 0
     
    # print("Max ", max(my_list))
    for i in range(1, max(my_list) + 1):
        indexes = []
        for j in range(len(my_list)):
            if my_list[j] in range(i, max(my_list) + 1):
                indexes.append(j)
        # print("indexes: ", indexes)
    
        tmp = 0
        for j in range(len(indexes) - 1):
            tmp += indexes[j + 1] - indexes[j] - 1
        # print(tmp)
    
        drops += tmp

    return drops

# demos
def test():
    my_list = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    assert calculate_trapped_rain_water(my_list) == 6

    my_list2 = [3, 0, 2, 0, 4]
    assert calculate_trapped_rain_water(my_list2) == 7

    my_list3 = [2, 0, 3]
    assert calculate_trapped_rain_water(my_list3) == 2

    my_list3 = [0, 10, 10, 0, 5]
    assert calculate_trapped_rain_water(my_list3) == 5

if __name__ == "__main__":
    test()
