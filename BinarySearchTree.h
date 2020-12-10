#pragma once

namespace bst {

    struct treeNodeBST {
        int val;
        treeNodeBST* right;
        treeNodeBST* left;
        treeNodeBST* father;
    };

    bool hasBothChildren(treeNodeBST* father) {
        return father->right != nullptr && father->left != nullptr;
    }

    void preOrder(treeNodeBST* r) {
        if (!r)
            return;
        std::cout << r->val << " ";
        if (r->left)
            preOrder(r->left);
        if (r->right)
            preOrder(r->right);
    }
    void inOrder(treeNodeBST* r) {
        if (!r)
            return;
        if (r->left)
            inOrder(r->left);
        std::cout << r->val << " ";
        if (r->right)
            inOrder(r->right);

    }
    void postOrder(treeNodeBST* r) {
        if (!r)
            return;
        if (r->left)
            postOrder(r->left);
        if (r->right);
        postOrder(r->right);
        std::cout << r->val << " ";
    }
    void addBSTNode(treeNodeBST*& r, int x) {
        if (!r) {
            treeNodeBST* newRoot = new treeNodeBST;
            newRoot->right = nullptr;
            newRoot->left = nullptr;
            newRoot->val = x;
            r = newRoot;
        }
        else {
            treeNodeBST* newSon = new treeNodeBST;
            if (r->val > x)
                addBSTNode(r->left, x);
            else
                addBSTNode(r->right, x);
        }
    }
    void addBSTNodeWithParent(treeNodeBST*& r, int x, treeNodeBST* parent = nullptr) {
        if (!r) {
            treeNodeBST* newRoot = new treeNodeBST;
            newRoot->right = nullptr;
            newRoot->left = nullptr;
            newRoot->val = x;
            newRoot->father = parent;
            r = newRoot;
        }
        else {
            if (x < r->val)
                addBSTNodeWithParent(r->left, x, r);

            else {
                addBSTNodeWithParent(r->right, x, r);
            }
        }
    }
    void deleteTree(treeNodeBST*& r) {
        if (!r)
            return;
        else {
            deleteTree(r->left);
            deleteTree(r->right);

            std::cout << "Deleteing treeNodeBST: " << r->val;
            delete r;
        }
    }
    void rotateR(treeNodeBST*& src) {
        treeNodeBST* srcParent = src->father;
        treeNodeBST* newSrc = src->left;
        src->left = newSrc->right;

        if (newSrc->right)
            newSrc->right->father = src;
        newSrc->right = src;
        src->father = newSrc;
        newSrc->father = srcParent;

        if (srcParent) {
            if (srcParent->left == src)
                srcParent->left = newSrc;
            else
                srcParent->right = newSrc;
        }
        src = newSrc;
    }
    void rotateL(treeNodeBST*& src) {
        treeNodeBST* srcParent = src->father;
        treeNodeBST* newSrc = src->right;
        src->right = newSrc->left;

        if (newSrc->left)
            newSrc->left->father = src;
        newSrc->left = src;
        src->father = newSrc;
        newSrc->father = srcParent;

        if (srcParent) {
            if (srcParent->right == src)
                srcParent->right = newSrc;
            else
                srcParent->left = newSrc;
        }
        src = newSrc;
    }
    void rotateRL(treeNodeBST*& src) {
        rotateR(src->left);
        rotateL(src);
    }
    void rotateLR(treeNodeBST*& src) {
        rotateL(src->right);
        rotateR(src);
    }

    treeNodeBST* findRecursive(treeNodeBST* r, int x) {
        if (!r)
            return 0;
        if (r->val == x)
            return r;
        else if (r->val > x)
            return findRecursive(r->left, x);
        else
            return findRecursive(r->right, x);
    }
    treeNodeBST* findSequential(treeNodeBST* r, int x) {
        while (r && r->val != x) {
            if (r->val > x)
                r = r->right;
            else
                r = r->left;
        }
        return r;
    }
    treeNodeBST* findMax(treeNodeBST* r) {
        while (r->right) {
            r = r->right;
        }
        return r;
    }
    treeNodeBST* findMin(treeNodeBST* r) {
        while (r->left) {
            r = r->left;
        }
        return r;
    }
    treeNodeBST* findSuccessorBST(treeNodeBST* srch) {
        /* nastepnik to wezel ktory jest odwiedzany jako nastepny idac metoda inorder
         * 1. istnieje prawe poddrzewo - szukamy miniumum w tym poddrezwie
         * 2. nie istnieje prawe poddrzewo - szukamy wezla bedacego najnizszym przodkiem wezla odniesienia, dla ktorego wezel odniesienia lezy w lewym poddrzewie */

        if (srch->right) {
            return findMin(srch->right);
        }

        treeNodeBST* tmp = srch->father;
        while (tmp != nullptr && tmp->left != srch) {
            srch = tmp;
            tmp = tmp->father;
        }

        return tmp;
    }
    treeNodeBST* findPredecessorBST(treeNodeBST* srch) {
        /* analogicznie jak przy szukaniu nastepnika*/

        if (srch->left) {
            return findMax(srch->left);
        }

        treeNodeBST* tmp = srch->father;
        while (tmp != nullptr && tmp->right != srch) {
            srch = tmp;
            tmp = tmp->father;
        }

        return tmp;
    }
    treeNodeBST* deleteBSTNodeValue(treeNodeBST* r, int x) {
        if (!r)
            return r;

        if (x < r->val)
            r->left = deleteBSTNodeValue(r->left, x);
        else if (x > r->val)
            r->right = deleteBSTNodeValue(r->right, x);
        else {
            if (r->left == nullptr) {
                treeNodeBST* tmp = r->right;
                delete r;
                return tmp;
            }
            else if (r->right == nullptr) {
                treeNodeBST* tmp = r->left;
                delete r;
                return tmp;
            }

            treeNodeBST* tmp = findMin(r->right);
            r->val = tmp->val;
            r->right = deleteBSTNodeValue(r->right, tmp->val);
        }
        return r;
    }
    treeNodeBST* deleteBSTNodeAddress(treeNodeBST* r, treeNodeBST* address) {
        if (!r)
            return r;

    }
    /*treeNodeBST* deleteBSTsubtreeFromVal(treeNodeBST* r, int fromWhere){
        if(!r)
            return r;
        else{

        }
    }
    treeNodeBST* deleteBSTsubtreeFromAdd(treeNodeBST* r, treeNodeBST* fromWhereAdd){
        return r;
    }*/
    treeNodeBST* rotateRight(treeNodeBST* src) {
        treeNodeBST* srcParent = src->father;
        treeNodeBST* newSrc = src->left;
        src->left = newSrc->right;

        if (newSrc->right)
            newSrc->right->father = src;
        newSrc->right = src;
        src->father = newSrc;
        newSrc->father = srcParent;

        if (srcParent) {
            if (srcParent->left == src)
                srcParent->left = newSrc;
            else
                srcParent->right = newSrc;
        }
        return newSrc;
    }
    treeNodeBST* rotateLeft(treeNodeBST* src) {
        treeNodeBST* srcParent = src->father;
        treeNodeBST* newSrc = src->right;
        src->right = newSrc->left;

        if (newSrc->left)
            newSrc->left->father = src;
        newSrc->left = src;
        src->father = newSrc;
        newSrc->father = srcParent;

        if (srcParent) {
            if (srcParent->right == src)
                srcParent->right = newSrc;
            else
                srcParent->left = newSrc;
        }
        return newSrc;
    }
    treeNodeBST* rotateRightLeft(treeNodeBST* src) {
        rotateRight(src->left);
        rotateLeft(src);
        return src;
    }
    treeNodeBST* rotateLeftRight(treeNodeBST* src) {
        rotateLeft(src->right);
        rotateRight(src);
        return src;
    }

}