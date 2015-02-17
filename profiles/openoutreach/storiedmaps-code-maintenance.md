# Guide to structure and updates of the StoriedMaps codebase #


Prepared by: Nedjo Rogers

Composition date: Feb. 16, 2015

Edit date: Feb. 16, 2015

Overview
========

StoriedMaps is a Drupal distribution focused on community mapping and
produced by Chocolate Lily for the University of Victoria department of
geography and related groups at UVic.


At a high level, the code comprising StoriedMaps can be broken into
three groups:


-   The Open Outreach distribution. StoriedMaps is built on Open
    Outreach, a Drupal distribution. Open Outreach code lives on
    drupal.org.

-   The StoriedMaps Core project on drupal.org.

-   Glue code. The Open Outreach distribution is combined with the
    StoriedMaps Core project on a GitHub repository, along with some
    “glue” code to connect the two.

Purpose
-------

This guide is intended to be a reference for individuals tasked with
updating and maintaining the StoriedMaps distribution.

Prerequisites
-------------

This guide assumes a familiarity with Git, the software used to manage
Drupal code, and with the ways that Git is used on both drupal.org and
GitHub. It further assumes that Git is installed on the machine of
anyone applying updates. See the following sources for some relevant
background:


-   [https://www.drupal.org/documentation/git](https://www.drupal.org/documentation/git)
    and sub-pages introduce Git for Drupal users.

-   [https://help.github.com/articles/set-up-git](https://help.github.com/articles/set-up-git)
    and subsequent pages give a general introduction to getting started
    with Git and GitHub.

Notes
-----


-   The workflow here assumes direct write access to GitHub
    repositories. While not covered here, a second somewhat more complex
    model, that of working in forks of the source repositories and
    submit pull requests, is also an option.

-   The steps here are intended as a minimal guide rather than a full
    approach. Usually, for example, one wouldn’t skip directly to git
    add but instead start with git status and git diff to be sure
    exactly what changes will be made before adding.


StoriedMaps Core
================

The Storiedmaps Core project includes three modules, each built with the
Features module to package configuration. These are:


-   StoriedMaps Core

-   StoriedMaps Icon

-   StoriedMaps Story


Changes to the functionality or design of the StoriedMaps site, such as
a tweak to a listing of icons or the appearance of a map, are made in
the form of Git commits to the StoriedMaps Core project. For those
changes to show up in the StoriedMaps distribution, the changes must be
applied as well to the StoriedMaps repository on GitHub.

Setup
-----

To make changes to StoriedMaps Core, ensure you have been assigned as a
maintainer with write access to the project on drupal.org.


Then follow the usual steps for cloning the repository, committing
changes to it, and pushing those changes to drupal.org. See
https://www.drupal.org/project/storiedmaps\_core/git-instructions.

The StoriedMaps repository on GitHub
====================================

The StoriedMaps repository on GitHub serves the purpose of integrating
the StoriedMaps Core module and related dependencies with Open Outreach.


StoriedMaps is written to build on and extend the Open Outreach
distribution. Most of the customization required for StoriedMaps is in
the StoriedMaps project on drupal.org:
[http://drupal.org/project/storiedmaps](http://drupal.org/project/storiedmaps)\_core.
However, some changes – additional modules as well as “glue” code - are
needed to turn Open Outreach into a StoriedMaps distribution. These
changes live on GitHub, as additions to and customizations of Open
Outreach.


Additions are:


-   The StoriedMaps Core module, and all of its dependencies not already
    in Open Outreach, are added to the directory
    profiles/openoutreach/modules/contrib.

-   The Masonry library is added to profiles/openoutreach/libraries.

-   The file storiedmaps\_logo.png is added to
    profiles/openoutreach/images.


“Glue” code and data includes:


-   Custom migration data and images are in
    profiles/openoutreach/modules/openoutreach\_features/openoutreach\_migrate/local.

-   The file
    profiles/openoutreach/openoutreach\_features/openoutreach\_migrate/openoutreach\_migrate.inc
    is customized to add migrations for StoriedMaps stories.

-   The file profiles/openoutreach/openoutreach.info is customized with
    StoriedMaps name and description as well as a custom set of
    subprofiles data, so that users installing can select from
    StoriedMaps features to install.

-   Some small customizations are made to
    profiles/openoutreach/openoutreach.install.inc so that StoriedMaps
    relevant messages, etc., appear at install time.

Structure of the StoriedMaps repository
---------------------------------------

The StoriedMaps repository is a “fork” of the openoutreach repository at
[https://github.com/nedjo/openoutreach](https://github.com/nedjo/openoutreach).
This means:


-   Updates to Open Outreach are not made directly in the StoriedMaps
    repository. Instead, they are made to the Open Outreach repository.

-   When updates have been made to the Open Outreach repository, they
    can be pulled from there to the StoriedMaps repository.

One-time setup for applying changes to StoriedMaps
--------------------------------------------------

In order to apply changes to StoriedMaps, you must be assigned write
access to the repository on GitHub.


To set up a local clone of the repository:


-   Clone the repository:
    ```
    git clone git@github.com:UVicCMC/storiedmaps.git
    ```

-   Change your location so you’re in the repository base directory:
    ```
    cd storiedmaps
    ```

-   Connect the repository with the Open Outreach repository by adding a
    “remote”:
    ```
    git remote add openoutreach git@github.com:nedjo/openoutreach.git
    ```

Updating Open Outreach on Github
--------------------------------

When a new release of Open Outreach is available, getting it to
StoriedMaps is a two step process:

1.  Update the openoutreach GitHub repo with the latest release of Open
    Outreach.

2.  Merge those changes into the StoriedMaps GitHub repo.


To update the Open Outreach repo, you must be assigned write access to
it.


To set up a local clone of the repository:


-   Clone the repository:
    ```
    git clone git@github.com:nedjo/openoutreach.git
    ```


Steps for updating to a new Open Outreach release are:


-   Remove all files from the openoutreach repository except the .git
    directory.

-   Download the latest Open Outreach release. Extract it into the root
    directory of the repository.

-   Add all changes:
    ```
    git add -A.
    ```

-   Commit the changes:
    ```
    git commit -m "Update to Open Outreach 7.x-1.15."
    ```

-   Push your changes:
    ```
    git push origin master
    ```

Updating StoriedMaps on GitHub
------------------------------

### Updating for changes in StoriedMaps Core or any of its dependencies not already in Open Outreach

The following modules are not in Open Outreach and so are added in the
StoriedMaps GitHub repo to profiles/openoutreach/modules/contrib:


-   [Conditional Fields](https://www.drupal.org/project/conditional_fields)

-   [Email](https://www.drupal.org/project/email)

-   [Masonry](https://www.drupal.org/project/masonry)
    (7.x-1.x branch)

-   [StoriedMaps Core](https://www.drupal.org/project/storiedmaps_core)


If there is a new version of StoriedMaps Core and/or any of the
dependencies available:


-   In your local clone of the StoriedMaps repository, delete the module
    you’re updating from profiles/openoutreach/modules/contrib.

-   Download the module from drupal.org and extract into
    profiles/openoutreach/modules/contrib.

-   Add your changes, using the -A option so that missing files are
    deleted:
    ```
    git add -A
    ```

-   Commit your change:
    ```
    git commit -m "Update to the latest dev version of StoriedMaps."
    ```

### Updating to a new release of Open Outreach

Once a new release of Open Outreach has been committed to the Open
Outreach repository on GitHub:


-   Pull the changes from the Open Outreach repo on GitHub (added above
    as a “remote”):
    ```
    git pull openoutreach master
    ```

-   Push them to GitHub
    ```
    git push origin master
    ```

### Making changes to the “glue” code and data, like changing the example pages

Say you want to add a “story” to be migrated.


-   Identify the file to be edited. In this case, that’s
    profiles/openoutreach/modules/openoutreach\_features/openoutreach\_migrate/local/story/csv.

-   Make your changes to the file, test them, and when you’re satisfied,
    commit them:
    ```
    git add .
    git commit -m "Add a new default story."
    ```
