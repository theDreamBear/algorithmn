// ==UserScript==
// @name         LeetCode Meta Title and Description Scraper
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  Scrape the og:title and og:description meta tag content from LeetCode problem pages
// @author       You
// @match        https://leetcode.com/problems/*
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    // Wait until the page loads completely
    window.onload = function() {
        // Select the meta tags
        let metaTitle = document.querySelector('meta[property="og:title"]');
        let metaDescription = document.querySelector('meta[property="og:description"]');

        // Get the content of the meta tags
        let titleContent = metaTitle ? metaTitle.getAttribute('content') : 'Title not found';
        let descriptionContent = metaDescription ? metaDescription.getAttribute('content') : 'Description not found';

        // Log the title and description to the console
        console.log("Title: ", titleContent);
        console.log("Description: ", descriptionContent);
    };
})();
