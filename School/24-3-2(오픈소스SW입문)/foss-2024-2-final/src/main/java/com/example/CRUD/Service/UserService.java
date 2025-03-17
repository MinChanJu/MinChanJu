package com.example.CRUD.Service;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.example.CRUD.Repository.UserJpaRepository;
import com.example.CRUD.model.User;

@Service
public class UserService {
    
    @Autowired private UserJpaRepository userJpaRepository;

    public long Create(User user) {
        userJpaRepository.save(user);
        return user.getId();
    }

    public List<User> findAll() {
        return userJpaRepository.findAll();
    }

    public Optional<User> findByUserName(String userName) {
        return userJpaRepository.findByUserName(userName);
    }

    public long UpdateById(User updateUser) {
        Optional<User> findUser = userJpaRepository.findById(updateUser.getId());
        if (findUser.isPresent()) {
            User user = findUser.get();
            user.setUserName(updateUser.getUserName());
            user.setUserPw(updateUser.getUserPw());
            user.setPhoneNumber(updateUser.getPhoneNumber());
            userJpaRepository.save(user);
            return user.getId();
        } else {
            return -1;
        }
    }

    public void DeleteById(long id) {
        userJpaRepository.deleteById(id);
    }
}
