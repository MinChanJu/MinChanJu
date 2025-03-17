package com.example.CRUD.Repository;

import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.CRUD.model.User;

@Repository
public interface UserJpaRepository extends JpaRepository<User, Long> {
    Optional<User> findByUserName(String userName);
    Optional<User> findByUserPw(String userPw);
    Optional<User> findByPhoneNumber(String phoneNumbe);
}
