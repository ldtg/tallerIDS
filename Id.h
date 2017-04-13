//
// Created by tg on 07/04/17.
//

#ifndef TP2_APP_ID_H
#define TP2_APP_ID_H

class Id {
 private:
  unsigned int src;
  unsigned int dst;
  unsigned short paqid;
 public:
  Id(unsigned int src, unsigned int dst, unsigned short id);
  Id();
  bool operator==(const Id &p) const;
  bool operator<(const Id &p) const;
  unsigned int getSrc() const;
  unsigned int getDst() const;
  unsigned short getPaqId() const;
};

#endif //TP2_APP_ID_H
