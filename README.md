# postit

## Introduction
This is a very simple module to demonstrate how to create a 
new type of entity. 

## Description
I am still struggling to understand fully how to create and use 
entities in Backdrop, one of the problems being that the example 
given in the Examples contrib module (Entity Example) no longer 
works because of the introduction a while ago of 'strict typing'.

In Backdrop, entities are real objects, and each type of entity has 
to create both its own entity controller and entity class.

For Drupal entities there is an excellent set of three posts by
Ronald Istos at 
https://www.bluespark.com/blog/drupal-entities-part-1-moving-beyond-nodes.
In the third part he works through a simple example called 'PostIt' and
here I have attempted to write a Backdrop version of this.

This example envisages the creation of PostIt notes, using a new type 
of entity 'postit'. The entity is defined in function 
postit_entity_info() which is an implementation of hook_entity_info().

A data table 'postit' is used to record the detail of each PostIt note
added to the system. The class Postit extends Backdrop's class Entity
to define the postit entity class, and class PostitController extends 
EntityDatabaseStorageController in order to add required special 
handling for postit objects.

## Status
This demonstration module is not yet complete. Any comments and 
suggestions are most welcome.

## Licence
This project is GPL v2 software. See the LICENSE.txt file in this
directory for complete text.

## Originator
Graham Oliver (github.com/Graham-72/)

