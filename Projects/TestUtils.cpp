#include "TestUtils.hpp"
#include <random>

bool TestUtils::compare(Brand c1, Brand c2)
{
    bool flag = c1.getId() == c2.getId() && c1.getName() == c2.getName();
    if (flag)
    {
        flag &= (c1.getProductAvailability().size() == c2.getProductAvailability().size());
    }
    if (flag)
    {
        int i = 0;
        while (flag && i < c1.getProductAvailability().size())
        {
            flag &= compare(c1.getProductAvailability()[i], c2.getProductAvailability()[i]);
            i++;
        }
    }
    return flag;
}

bool TestUtils::compareResponses(SearchResponse r1, SearchResponse r2)
{
    bool flag = r1.getResults().size() == r2.getResults().size() && r1.getTotalCount() == r2.getTotalCount();
    if (flag)
    {
        std::map<std::string, Brand> brandMap1;
        std::map<std::string, Brand> brandMap2;
        for (auto &brand : r1.getResults())
        {
            brandMap1[brand.getId()] = brand;
        }
        for (auto &brand : r2.getResults())
        {
            brandMap2[brand.getId()] = brand;
            if (brandMap1.find(brand.getId()) == brandMap1.end())
            {
                return false;
            }
            if (!compare(brandMap1[brand.getId()], brand))
            {
                return false;
            }
        }
        for (auto &brand : r1.getResults())
        {
            if (brandMap2.find(brand.getId()) == brandMap2.end())
            {
                return false;
            }
            if (!compare(brandMap2[brand.getId()], brand))
            {
                return false;
            }
        }
    }
    return flag;
}

bool TestUtils::compare(ProductAvailability va1, ProductAvailability va2)
{
    return va1.getId() == va2.getId();
}

std::string TestUtils::random_string(size_t length)
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::string str1 = "";
    for (int i = 0; i < length; i++)
    {
        str1 = str1 + str.at(rand() % 20);
    }
    return str1; // assumes 32 < number of characters in str
}

bool TestUtils::compareVector(SearchResponse response, Brand brand)
{
    for (auto &resultBrand : response.getResults())
    {
        if (resultBrand.getId() == brand.getId())
        {
            return true;
        }
    }
    return false;
}

bool TestUtils::contains(std::vector<ProductAvailability> products, ProductAvailability product)
{
    for (auto &productFromArray : products)
    {
        if (productFromArray.getId() == product.getId())
        {
            return true;
        }
    }
    return false;
}

ProductAvailability *TestUtils::getProductAvailabilityById(std::vector<ProductAvailability> &productAvailabilities, std::string id)
{
    for (auto &productAvailability : productAvailabilities)
    {
        if (productAvailability.getId() == id)
            return &productAvailability;
    }
    return nullptr;
}
