#define BOOST_TEST_MODULE sku_manager_tests

#include <boost/test/unit_test.hpp>
#include "services/SKUManagerImpl.hpp"
#include "TestUtils.hpp"

BOOST_AUTO_TEST_SUITE(tests_suite)

BOOST_AUTO_TEST_CASE(testAddBrandSuccess)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel},
              {SKU::SubCategoryType::footwear}, {});
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  Brand fetchedBrand = skuManager->get(brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getId(), brandId);
}

BOOST_AUTO_TEST_CASE(testAddBrandFailure)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  BOOST_CHECK_EQUAL(0, skuManager->add(Brand("", "", {}, {}, {})));
  std::string brandId = TestUtils::random_string(10);
  Brand brand1(brandId, "Brand A", {SKU::CategoryType::apparel},
               {SKU::SubCategoryType::footwear}, {});
  BOOST_CHECK_EQUAL(1, skuManager->add(brand1));
  Brand brand2(brandId, "Brand B", {SKU::CategoryType::beverages},
               {SKU::SubCategoryType::coffee}, {});
  BOOST_CHECK_EQUAL(0, skuManager->add(brand2));
}

BOOST_AUTO_TEST_CASE(testAddAvailabilitySuccess)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::beverages, SKU::SubCategoryType::coffee, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability2));
  Brand fetchedBrand = skuManager->get(brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getId(), brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getProductAvailability().size(), 2);
}

BOOST_AUTO_TEST_CASE(testAddAvailabilityFailure)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  ProductAvailability emptyAvailability("", SKU::CategoryType::none_category, SKU::SubCategoryType::none_sub_category, 0, 0);
  BOOST_CHECK_EQUAL(0, skuManager->addAvailability(brandId, emptyAvailability));
  Brand brand(brandId, std::string("Brand A"), {SKU::CategoryType::apparel, SKU::CategoryType::beverages}, {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability));
  BOOST_CHECK_EQUAL(0, skuManager->addAvailability(brand.getId(), productAvailability));
}

BOOST_AUTO_TEST_CASE(testUpdateAvailabilityNonExistent)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  ProductAvailability emptyAvailability("", SKU::CategoryType::none_category, SKU::SubCategoryType::none_sub_category, 0, 0);
  BOOST_CHECK_EQUAL(0, skuManager->updateAvailability(brandId, emptyAvailability));
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(0, skuManager->updateAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  Brand fetchedBrand = skuManager->get(brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getId(), brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getProductAvailability().size(), 1);
  BOOST_CHECK_EQUAL(0, skuManager->updateAvailability(brand.getId(), productAvailability2));
}

BOOST_AUTO_TEST_CASE(testUpdateAvailabilitySuccess)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);

  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability updatedProductAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 9, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability2));
  BOOST_CHECK_EQUAL(1, skuManager->updateAvailability(brand.getId(), updatedProductAvailability2));
  Brand fetchedBrand = skuManager->get(brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getId(), brandId);
  BOOST_CHECK_EQUAL(1, TestUtils::contains(fetchedBrand.getProductAvailability(), updatedProductAvailability2));
}

BOOST_AUTO_TEST_CASE(testRemoveAvailabilityNonExistent)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  ProductAvailability emptyAvailability("", SKU::CategoryType::none_category, SKU::SubCategoryType::none_sub_category, 0, 0);
  BOOST_CHECK_EQUAL(0, skuManager->removeAvailability(brandId, emptyAvailability));
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(0, skuManager->removeAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(0, skuManager->removeAvailability(brand.getId(), productAvailability2));
}

BOOST_AUTO_TEST_CASE(testRemoveAvailabilitySuccess)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability2));
  BOOST_CHECK_EQUAL(1, skuManager->removeAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->removeAvailability(brand.getId(), productAvailability2));
  Brand fetchedBrand = skuManager->get(brandId);
  BOOST_CHECK_EQUAL(fetchedBrand.getProductAvailability().size(), 0);
  BOOST_CHECK_EQUAL(0, skuManager->removeAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(0, skuManager->removeAvailability(brand.getId(), productAvailability2));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability2));
}

BOOST_AUTO_TEST_CASE(testBookProductFailure)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brandId, SKU::CategoryType::apparel, SKU::SubCategoryType::clothing));
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::beverages, SKU::SubCategoryType::coffee, 10, 0);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::footwear));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::beverages, SKU::SubCategoryType::tea));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::footwear));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::clothing));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::beverages, SKU::SubCategoryType::tea));
}

BOOST_AUTO_TEST_CASE(testBookProductSuccess)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  std::string brandId = TestUtils::random_string(10);
  Brand brand(brandId, "Brand A", {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
              {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  ProductAvailability productAvailability1 = ProductAvailability("1", SKU::CategoryType::beverages, SKU::SubCategoryType::coffee, 10, 0);
  ProductAvailability productAvailability2 = ProductAvailability("2", SKU::CategoryType::apparel, SKU::SubCategoryType::clothing, 1, 0);
  ProductAvailability emptyProductAvailability = ProductAvailability("asdZxcdvf", SKU::CategoryType::beverages, SKU::SubCategoryType::coffee, -1, -1);
  BOOST_CHECK_EQUAL(1, skuManager->add(brand));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability1));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::clothing));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::footwear));
  BOOST_CHECK_EQUAL(1, skuManager->bookProduct(brand.getId(), SKU::CategoryType::beverages, SKU::SubCategoryType::coffee));
  BOOST_CHECK_EQUAL(1, skuManager->addAvailability(brand.getId(), productAvailability2));
  BOOST_CHECK_EQUAL(1, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::clothing));
  BOOST_CHECK_EQUAL(0, skuManager->bookProduct(brand.getId(), SKU::CategoryType::apparel, SKU::SubCategoryType::clothing));
  Brand fetchedBrand = skuManager->get(brandId);
  std::vector<ProductAvailability> fetchedProductAvailabilities = fetchedBrand.getProductAvailability();
  ProductAvailability fetchedProductAvailability1 = TestUtils::getProductAvailabilityById(fetchedProductAvailabilities, "1") == nullptr ? emptyProductAvailability : *TestUtils::getProductAvailabilityById(fetchedProductAvailabilities, "1");
  ProductAvailability fetchedProductAvailability2 = TestUtils::getProductAvailabilityById(fetchedProductAvailabilities, "2") == nullptr ? emptyProductAvailability : *TestUtils::getProductAvailabilityById(fetchedProductAvailabilities, "2");
  BOOST_CHECK_EQUAL(fetchedProductAvailability1.getAvailableQuantityCount(), 9);
  BOOST_CHECK_EQUAL(fetchedProductAvailability2.getAvailableQuantityCount(), 0);
}

BOOST_AUTO_TEST_CASE(testSearchEmptyCategoryTypeEmptySubCategoryType)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  SearchResponse expectedResponse = SearchResponse(0, {});
  SearchResponse actualResponse = skuManager->search(SKU::CategoryType::none_category, SKU::SubCategoryType::none_sub_category);
  BOOST_CHECK_EQUAL(expectedResponse.getTotalCount(), actualResponse.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse, actualResponse));
}

BOOST_AUTO_TEST_CASE(testSearchEmptyCategoryTypeAndNonEmptySubCategoryType)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  Brand brand1 = Brand("1", "Brand A",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},

                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand2 = Brand("2", "Brand B",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},

                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  SearchResponse expectedResponse1 = SearchResponse(0, {});
  SearchResponse actualResponse1 = skuManager->search(SKU::CategoryType::none_category, SKU::SubCategoryType::clothing);
  BOOST_CHECK_EQUAL(expectedResponse1.getTotalCount(), actualResponse1.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse1, actualResponse1));
  skuManager->add(brand1);
  SearchResponse expectedResponse2 = SearchResponse(0, {});
  SearchResponse actualResponse2 = skuManager->search(SKU::CategoryType::none_category, SKU::SubCategoryType::clothing);
  BOOST_CHECK_EQUAL(expectedResponse2.getTotalCount(), actualResponse2.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse2, actualResponse2));
  skuManager->add(brand2);
  SearchResponse expectedResponse3 = SearchResponse(0, {});
  SearchResponse actualResponse3 = skuManager->search(SKU::CategoryType::none_category, SKU::SubCategoryType::clothing);
  BOOST_CHECK_EQUAL(expectedResponse3.getTotalCount(), actualResponse3.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse3, actualResponse3));
}

BOOST_AUTO_TEST_CASE(testSearchNonEmptyCategoryTypeAndEmptySubCategoryType)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  Brand brand1 = Brand("1", "Brand A",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},

                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand2 = Brand("2", "Brand B",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  SearchResponse expectedResponse1 = SearchResponse(0, {});
  SearchResponse actualResponse1 = skuManager->search(SKU::CategoryType::apparel, SKU::SubCategoryType::none_sub_category);
  BOOST_CHECK_EQUAL(expectedResponse1.getTotalCount(), actualResponse1.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse1, actualResponse1));
  skuManager->add(brand1);
  SearchResponse expectedResponse2 = SearchResponse(0, {});
  SearchResponse actualResponse2 = skuManager->search(SKU::CategoryType::apparel, SKU::SubCategoryType::none_sub_category);
  BOOST_CHECK_EQUAL(expectedResponse2.getTotalCount(), actualResponse2.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse2, actualResponse2));
  skuManager->add(brand2);
  SearchResponse expectedResponse3 = SearchResponse(0, {});
  SearchResponse actualResponse3 = skuManager->search(SKU::CategoryType::apparel, SKU::SubCategoryType::none_sub_category);
  BOOST_CHECK_EQUAL(expectedResponse3.getTotalCount(), actualResponse3.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse3, actualResponse3));
}

BOOST_AUTO_TEST_CASE(testSearchCategoryTypeAndSubCategoryType)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  Brand brand1 = Brand("1", "Brand A",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand2 = Brand("2", "Brand B",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand3("3", "Brand C", {SKU::CategoryType::beverages}, {SKU::SubCategoryType::coffee}, {});
  skuManager->add(brand1);
  skuManager->add(brand2);
  skuManager->add(brand3);
  SearchResponse expectedResponse1 = SearchResponse(2, {brand1, brand2});
  SearchResponse actualResponse1 = skuManager->search(SKU::CategoryType::apparel, SKU::SubCategoryType::clothing);
  BOOST_CHECK_EQUAL(expectedResponse1.getTotalCount(), actualResponse1.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse1, actualResponse1));

  SearchResponse expectedResponse2 = SearchResponse(0, {});
  SearchResponse actualResponse2 = skuManager->search(SKU::CategoryType::apparel, SKU::SubCategoryType::footwear);
  BOOST_CHECK_EQUAL(expectedResponse2.getTotalCount(), actualResponse2.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse2, actualResponse2));

  SearchResponse expectedResponse3 = SearchResponse(3, {brand1, brand2, brand3});
  SearchResponse actualResponse3 = skuManager->search(SKU::CategoryType::beverages, SKU::SubCategoryType::coffee);
  BOOST_CHECK_EQUAL(expectedResponse3.getTotalCount(), actualResponse3.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse3, actualResponse3));

  SearchResponse expectedResponse4 = SearchResponse(0, {});
  SearchResponse actualResponse4 = skuManager->search(SKU::CategoryType::beverages, SKU::SubCategoryType::tea);
  BOOST_CHECK_EQUAL(expectedResponse4.getTotalCount(), actualResponse4.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse4, actualResponse4));
}

BOOST_AUTO_TEST_CASE(testMultiSearch)
{
  SKUManagerImpl *skuManager = new SKUManagerImpl();
  Brand brand1 = Brand("1", "Brand A",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand2 = Brand("2", "Brand B",
                       {SKU::CategoryType::apparel, SKU::CategoryType::beverages},
                       {SKU::SubCategoryType::clothing, SKU::SubCategoryType::coffee}, {});
  Brand brand3("3", "Brand C", {SKU::CategoryType::beverages},
               {SKU::SubCategoryType::tea}, {});

  SearchRequest searchRequest1(SKU::CategoryType::apparel, SKU::SubCategoryType::footwear);
  SearchResponse expectedResponse1 = SearchResponse(0, {});
  SearchResponse actualResponse1 = skuManager->search({searchRequest1});
  BOOST_CHECK_EQUAL(expectedResponse1.getTotalCount(), actualResponse1.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse1, actualResponse1));

  skuManager->add(brand1);
  skuManager->add(brand2);
  skuManager->add(brand3);

  SearchRequest searchRequest2(SKU::CategoryType::apparel, SKU::SubCategoryType::footwear);
  SearchResponse expectedResponse2 = SearchResponse(0, {});
  SearchResponse actualResponse2 = skuManager->search({searchRequest2});
  BOOST_CHECK_EQUAL(expectedResponse2.getTotalCount(), actualResponse2.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareResponses(expectedResponse2, actualResponse2));

  SearchRequest searchRequest31(SKU::CategoryType::apparel, SKU::SubCategoryType::footwear);
  SearchRequest searchRequest32(SKU::CategoryType::apparel, SKU::SubCategoryType::clothing);
  SearchResponse expectedResponse3 = SearchResponse(2, {brand1,brand2});
  SearchResponse actualResponse3 = skuManager->search({searchRequest31, searchRequest32});
  BOOST_CHECK_EQUAL(expectedResponse3.getTotalCount(), actualResponse3.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse3, brand1));
  BOOST_CHECK_EQUAL(0, TestUtils::compareVector(actualResponse3, brand3));

  SearchRequest searchRequest4(SKU::CategoryType::apparel, SKU::SubCategoryType::clothing);
  SearchResponse expectedResponse4 = SearchResponse(2, {brand1,brand2});
  SearchResponse actualResponse4 = skuManager->search({searchRequest4});
  BOOST_CHECK_EQUAL(expectedResponse4.getTotalCount(), actualResponse4.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse4, brand1));
  BOOST_CHECK_EQUAL(0, TestUtils::compareVector(actualResponse4, brand3));

  SearchRequest searchRequest51(SKU::CategoryType::apparel, SKU::SubCategoryType::clothing);
  SearchRequest searchRequest52(SKU::CategoryType::beverages, SKU::SubCategoryType::tea);
  SearchResponse expectedResponse5 = SearchResponse(3, {brand1, brand3});
  SearchResponse actualResponse5 = skuManager->search({searchRequest51, searchRequest52});
  BOOST_CHECK_EQUAL(expectedResponse5.getTotalCount(), actualResponse5.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse5, brand1));
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse5, brand3));

  SearchRequest searchRequest61(SKU::CategoryType::apparel, SKU::SubCategoryType::clothing);
  SearchRequest searchRequest62(SKU::CategoryType::apparel, SKU::SubCategoryType::footwear);
  SearchRequest searchRequest63(SKU::CategoryType::beverages, SKU::SubCategoryType::coffee);
  SearchRequest searchRequest64(SKU::CategoryType::beverages, SKU::SubCategoryType::tea);
  SearchResponse expectedResponse6 = SearchResponse(3, {brand1, brand2, brand3});
  SearchResponse actualResponse6 = skuManager->search({searchRequest61, searchRequest62, searchRequest63, searchRequest64});
  BOOST_CHECK_EQUAL(expectedResponse6.getTotalCount(), actualResponse6.getTotalCount());
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse6, brand1));
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse6, brand2));
  BOOST_CHECK_EQUAL(1, TestUtils::compareVector(actualResponse6, brand3));
}

BOOST_AUTO_TEST_SUITE_END()